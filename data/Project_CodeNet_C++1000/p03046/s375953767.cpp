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
#define mp make_pair

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int32 m,k;
    cin >> m >> k;
    if(k >= (1 << m)){
        ANS(-1);
        return 0;
    }
    if(m == 0){
        if(k == 0)
            ANS("0 0");
        return 0;
    }
    if(m == 1){
        if(k == 0){
            ANS("0 0 1 1");
        }else{
            ANS(-1);
        }
        return 0;
    }
    REP(i,1<<m){
        if(i == k)continue;
        cout << i << " ";
    }
    cout << k << " ";
    FORR(i,(1<<m)-1,0){
        if(i == k)continue;
        cout << i << " ";
    }
    cout << k << endl;
    return 0;
}