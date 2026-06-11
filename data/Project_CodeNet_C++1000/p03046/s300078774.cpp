#include <bits/stdc++.h>
#define REP(i, e) for(int (i) = 0; (i) < (e); ++(i))
#define FOR(i, b, e) for(int (i) = (b); (i) < (e); ++(i))
#define ALL(c) (c).begin(), (c).end()
#define PRINT(x) cout << (x) << "\n"
using namespace std;
using ll = long long; using pint = pair<int, int>; using pll = pair<ll, ll>;
const long long MOD = 1000000007;

ll M, K;

signed main(){
    cin >> M >> K;
    if((1 << M) <= K){
        PRINT("-1");
        return 0;
    }
    if(M == 0){
        cout << "0 0" << endl;
        return 0;
    }
    if(M == 1){
        if(K == 0) cout << "0 0 1 1" << endl;
        else PRINT("-1");
        return 0;
    }
    for(ll i = 0; i < (1 << M); i++){
        if(i == K) continue;
        cout << i << " ";
    }
    cout << K << " ";
    for(ll i = (1 << M) - 1; i >= 0; i--){
        if(i == K) continue;
        cout << i << " ";
    }
    cout << K << endl;
    return 0;
}