#include <bits/stdc++.h>
using namespace std;

using int32 = int_fast32_t;
using int64 = int_fast64_t;

const int32 INF = 1e9;
const int32 MOD = 1e9+7;
const int64 LLINF = 1e18;

#define YES(n) cout << ((n) ? "YES\n" : "NO\n"  )
#define Yes(n) cout << ((n) ? "Yes\n" : "No\n"  )
#define ANS(n) cout << (n) << "\n"
#define REP(i,n) for(int64 i=0;i<(n);++i)
#define FOR(i,a,b) for(int64 i=(a);i<(b);i++)
#define FORR(i,a,b) for(int64 i=(a);i>=(b);i--)
#define ALL(obj) (obj).begin(),(obj).end()
#define pii pair<int32,int32>
#define pll pair<int64,int64>
#define pb(a) push_back(a)
#define mp make_pair

int32 matchNeeded[10] = {-1, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int32 n, m;
    cin >> n >> m;
    vector<int32> a(m);
    REP(i,m)cin >> a[i];
    sort(ALL(a));
    vector<int32> digits(n+1, -INF);
    digits[0] = 0;
    FOR(i,1,n+1){
        REP(j,m){
            if(i - matchNeeded[a[j]] < 0)continue;
            digits[i] = max(digits[i], digits[i - matchNeeded[a[j]]] + 1);
        }
    }
    while(n > 0){
        FORR(i,m-1,0){
            if(n - matchNeeded[a[i]] < 0)continue;
            if(digits[n] - digits[n - matchNeeded[a[i]]] == 1){
                cout << a[i];
                n -= matchNeeded[a[i]];
                break;
            }
        }
    }
    cout << endl;
    return 0;
}