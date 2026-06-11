#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<vector>
#include<utility>
#include<queue>
#include<deque>
#include<stack>
#include<set>
#include<map>
#include<bitset>
#include<string>
#define MOD 1000000007
typedef long long ll;
using namespace std;

template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

int A[305][305];

int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    ll H,W,D; cin >> H >> W >> D;
    vector<pair<ll,ll>> v(H*W+1);
    for(ll i=1;i<=H;i++){
        for(ll j=1;j<=W;j++){
            cin >> A[i][j];
            v[A[i][j]] = make_pair(i,j);
        }
    }

    ll S[90005];
    Fill(S,0);
    for(ll d=1;d<=D;d++){
        for(ll l=0;d+(l+1)*D <= H*W;l++){
            S[d+(l+1)*D] = S[d+l*D] + abs(v[d+(l+1)*D].first - v[d+l*D].first) + abs(v[d+(l+1)*D].second - v[d+l*D].second); 
        }
    }

    ll Q; cin >> Q;
    for(ll i=0;i<Q;i++){
        ll L,R; cin >> L >> R;
        cout << S[R] - S[L] << "\n";
    }
    return 0;
}