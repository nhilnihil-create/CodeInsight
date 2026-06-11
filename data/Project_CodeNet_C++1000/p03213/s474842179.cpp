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
    int32 n;
    cin >> n;
    vector<int32> fac(n+1);
    FOR(i,2,n+1){
        int32 p = 2;
        int32 x = i;
        while(p * p <= x){
            while(x % p == 0){
                fac[p]++;
                x /= p;
            }
            ++p;
        }
        if(x != 1)fac[x]++;
    }
    int32 ans = 0;
    FOR(i,2,n+1){
        if(fac[i] >= 74)ans++;
    }
    FOR(i,2,n+1)FOR(j,2,n+1){
        if(i == j)continue;
        if(fac[i] >= 2 && fac[j] >= 24)ans++;
    }
    FOR(i,2,n+1)FOR(j,2,n+1){
        if(i == j)continue;
        if(fac[i] >= 4 && fac[j] >= 14)ans++;
    }
    FOR(i,2,n+1)FOR(j,2,n+1)FOR(k,2,n+1){
        if(i == j || j == k || k == i)continue;
        if(j > k)continue;
        if(fac[i] >= 2 && fac[j] >= 4 && fac[k] >= 4)ans++;
    }
    ANS(ans);
    return 0;
}