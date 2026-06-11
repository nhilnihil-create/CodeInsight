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
    int32 n,q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<pair<char,char>> spell(q);
    REP(i,q){
        char t, d;
        cin >> t >> d;
        spell[i] = pair<char,char>(t,d);
    }
    int32 l = 0, r = n;
    while(r - l > 1){
        int32 m = (l + r) / 2;
        int32 idx = m;
        REP(i,q){
            if(spell[i].first == s[idx]){
                if(spell[i].second == 'L'){
                    idx--;
                }else{
                    idx++;
                }
            }
            if(idx < 0 || n <= idx)break;
        }
        if(idx < 0){
            l = m;
        }else{
            r = m;
        }
    }
    int32 l2 = 0,r2 = n;
    while(r2 - l2 > 1){
        int32 m = (l2 + r2) / 2;
        int32 idx = m;
        REP(i,q){
            if(spell[i].first == s[idx]){
                if(spell[i].second == 'L'){
                    idx--;
                }else{
                    idx++;
                }
            }
            if(idx < 0 || n <= idx)break;
        }
        if(n <= idx){
            r2 = m;
        }else{
            l2 = m;
        }
    }
    ANS(r2 - r);
    return 0;
}