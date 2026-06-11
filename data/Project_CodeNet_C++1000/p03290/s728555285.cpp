#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
typedef pair<ll,ll> P;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define EFOR(i,a,b) for(int i=(a);i<=(b);++i)
#define REP(i, n) FOR(i,0,n)
#define IINF 1e9

// bit全探索
int main(void){
    int d,g,ans = IINF;
    cin >> d >> g;
    vector<int> p(d+10);
    vector<ll> c(d+10);
    REP(i,d) cin >> p[i] >> c[i];
    
    FOR(b,0,(1 << d)){
        int res = 0,num = 0,mnum = -1;
        REP(i,d){
            if((b >> i) & 1){
                res += (c[i] + 100 * (i+1) * p[i]);
                num += p[i];
            }
            else{
                mnum = i;
            }
        }
        if(res < g){
            int m = 100 * (mnum + 1);
            int need = (g - res + (m - 1)) / m ;
            if(need >= p[mnum]) continue;
            num += need;
            res += need * m;
        }
        if(res >= g) ans = min(ans,num);
        
    }
    cout << ans << endl;
    return 0;
}