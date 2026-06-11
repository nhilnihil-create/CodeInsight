#include <bits/stdc++.h>
using namespace std;

using int32 = int_fast32_t;
using int64 = int_fast64_t;

const int32 INF = 1e9;
const int32 MOD = 1e9+7;
const int64 LLINF = 1e18;

#define YES(n) cout << ((n) ? "YES\n" : "NO\n"  )
#define Yes(n) cout << ((n) ? "Yes\n" : "No\n"  )
#define POSSIBLE cout << ((n) ? "POSSIBLE\n" : "IMPOSSIBLE\n"  )
#define ANS(n) cout << (n) << "\n"
#define REP(i,n) for(int64 i=0;i<(n);++i)
#define FOR(i,a,b) for(int64 i=(a);i<(b);i++)
#define FORR(i,a,b) for(int64 i=(a);i>=(b);i--)
#define ALL(obj) (obj).begin(),(obj).end()
#define pii pair<int32,int32>
#define pll pair<int64,int64>
#define pb(a) push_back(a)

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int32 n,a,b;
    cin >> n >> a >> b;
    if(n < a + b - 1 || a * b < n){
        ANS(-1);
        return 0;
    }
    FORR(i,b,1){
        cout << i << " ";
    }
    int32 remain = n - b;
    FORR(i,a-1,1){
        int32 l = remain / i;
        remain -= l;
        REP(j,l)cout << n - remain - j << " ";
    }
    cout << endl;
    return 0;
}