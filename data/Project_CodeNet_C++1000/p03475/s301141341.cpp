#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
long long mo = 1e9 + 7;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
template<class T, class S> void cmin(T &a, const S &b) { if (a > b)a = b; }
template<class T, class S> void cmax(T &a, const S &b) { if (a < b)a = b; }

int main(){
    ll N;
    cin >> N;
    vector<ll> C(N-1),S(N-1), F(N-1);
    rep(i,N-1){
        cin >> C[i] >> S[i] >> F[i];
    }
    rep(i,N-1){
        ll cur = 0;
        for(int j=i;j<N-1;j++){
            cur = max(((cur + F[j] - ll(1))/F[j])*F[j] ,S[j]);
            cur += C[j];
        }
        cout << cur << endl;
    }
    cout << 0 << endl;
}
