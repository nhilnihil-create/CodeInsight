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
#define REP(i,n) for(int64 i=0;i<(int64)(n);++i)
#define FOR(i,a,b) for(int64 i=(a);i<(int64)(b);i++)
#define FORR(i,a,b) for(int64 i=(a);i>=(b);i--)
#define ALL(obj) (obj).begin(),(obj).end()
#define pii pair<int32,int32>
#define pll pair<int64,int64>
#define pb(a) push_back(a)
#define mp make_pair


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int32 n,k;
    cin >> n >> k;
    map<int32,int32> compression;
    int32 variationsCnt = 0;
    vector<vector<int32>> td;
    REP(i,n){
        int32 t, d;
        cin >> t >> d;
        if(compression[t] == 0){
            compression[t] = variationsCnt+1;
            variationsCnt++;
            td.pb(vector<int32>(1, d));
        }else{
            td[compression[t]-1].pb(d);
        }
    }
    vector<int32> mx;
    vector<int32> others;
    REP(i,td.size()){
        sort(ALL(td[i]),greater<int32>());
        mx.pb(td[i][0]);
        FOR(j,1,td[i].size())
            others.pb(td[i][j]);
    }
    sort(ALL(mx),greater<int32>());
    sort(ALL(others), greater<int32>());
    vector<int64> mxRuiseki(mx.size()+1);
    mxRuiseki[0] = 0;
    REP(i,mx.size()){
        mxRuiseki[i+1] = mxRuiseki[i] + mx[i];
    }
    vector<int64> othersRuiski(others.size()+1);
    othersRuiski[0] = 0;
    REP(i,others.size()){
        othersRuiski[i+1] = othersRuiski[i] + others[i];
    }
    int64 ans = 0;
    FOR(i,max<int64>(1, k - others.size()),min<int64>(k,mx.size())+1){
        ans = max(ans, mxRuiseki[i] + othersRuiski[k - i] + i * i);
    }
    ANS(ans);
    return 0;
}