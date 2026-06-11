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
    int32 n,k;
    cin >> n >> k;
    vector<int32> l,r;
    r.push_back(0);
    REP(i,n){
        int32 x;
        cin >> x;
        if(x < 0){
            l.push_back(-x);
        }else if(0 < x){
            r.push_back(x);
        }else{
            k--;
        }
    }
    l.push_back(0);
    reverse(ALL(l));
    int32 ans = INF;
    REP(i,k+1){
        int32 a = INF, b = INF;
        if(i < l.size())
            a = l[i];
        if(k-i < r.size())
            b = r[k-i];
        ans = min({ans, a+b*2, a*2+b});
    }
    ANS(ans);
    return 0;
}