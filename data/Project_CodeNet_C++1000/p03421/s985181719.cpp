#pragma GCC target ("avx2")
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("O3")
#include "bits/stdc++.h"
#include <unordered_set>
#include <unordered_map>
#include <random>
using namespace std;
typedef long long ll;
const ll MOD = /*1'000'000'007LL;*/ 998'244'353LL;
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for(int (i)=0; (i)<(n); (i)++)
const int dx[4]={ 1,0,-1,0 };
const int dy[4]={ 0,1,0,-1 };

ll N, A, B;

signed main(){
    cin >> N >> A >> B;
    if(N < A+B-1 || A*B < N){
        cout << -1 << endl;
        return 0;
    }

    vector<ll> v;
    int k = N-A;
    for(ll i=0; i<A; i++){
        for(ll j=0; k>0&&j<B-1; j++){
            v.pb((i+1)*B-1-j);
            k--;
        }
        v.pb(i*B);
    }

    vector<ll> z = v;
    sort(all(z));
    rep(i, v.size()){
        cout << lower_bound(all(z), v[i]) - z.begin() + 1 << endl;
    }
}