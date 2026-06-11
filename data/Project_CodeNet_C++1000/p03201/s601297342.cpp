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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int32 n;
    cin >> n;
    map<int32,int32> a;
    REP(i,n){
        int32 ai;
        cin >> ai;
        a[ai]++;
    }
    int32 ans = 0;
    for(auto it = a.rbegin(); it != a.rend(); it++){
        int32 x = it->first;
        int32 y = it->second;
        if(y > 0){
            int64 sum = 2;
            while(sum <= x){
                sum <<= 1;
            }
            int32 mn;
            if(x + x == sum){
                mn = a[x] / 2;
            }else{
                mn = min(y, a[sum-x]);
            }
            it->second -= mn;
            a[sum-x] -= mn;
            ans += mn;
        }
    }
    ANS(ans);
    return 0;
}