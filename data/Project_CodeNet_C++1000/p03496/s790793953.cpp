#include <bits/stdc++.h>
#define REP(i, e) for(int (i) = 0; (i) < (e); ++(i))
#define FOR(i, b, e) for(int (i) = (b); (i) < (e); ++(i))
#define ALL(c) (c).begin(), (c).end()
#define PRINT(x) cout << (x) << "\n"
using namespace std;
using ll = long long; using pint = pair<int, int>; using pll = pair<ll, ll>;
const long long MOD = 1000000007;

ll N, a[100];

signed main(){
    cin >> N;
    ll M = 0, m = 0, pos = 0, neg = 0;
    REP(i, N){
        cin >> a[i];
        if(a[i] > a[M]) M = i;
        if(a[i] < a[m]) m = i;
        if(a[i] > 0) pos++;
        if(a[i] < 0) neg++;
    }
    if(abs(a[m]) <= abs(a[M])){
        PRINT(neg + N - 1);
        REP(i, N){
            if(a[i] < 0){
                cout << M + 1 << " " << i + 1 << endl;
            }
        }
        REP(i, N - 1){
            cout << i + 1 << " " << i + 2 << endl;
        }
    }else{
        PRINT(pos + N - 1);
        REP(i, N){
            if(a[i] > 0){
                cout << m + 1 << " " << i + 1 << endl;
            }
        }
        for(ll i = N - 1; i >= 1; i--){
            cout << i + 1 << " " << i << endl;
        }
    }
    return 0;
}