#pragma GCC target ("avx2")
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("O3")
#include "bits/stdc++.h"
#include <unordered_set>
#include <unordered_map>
#include <random>
using namespace std;
typedef long long ll;
const ll MOD = 1'000'000'007LL; /*998'244'353LL;*/
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for(int (i)=0; (i)<(n); (i)++)
const int dx[4]={ 1,0,-1,0 };
const int dy[4]={ 0,1,0,-1 };

int N, K;

signed main(){
    cin >> N >> K;
    if(K == 0){
        cout << (ll)N*N << endl;
        return 0;
    }
    ll ans = 0;
    for(int b=K+1; b<=N; b++){
        ll tmp = (N)/b;
        ans += tmp * (b-K);
        ll tmp2 = N%b;
        if(tmp2 >= K) ans += tmp2-K+1;
    }
    cout << ans << endl;
}