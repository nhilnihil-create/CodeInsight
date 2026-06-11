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
    string s;
    cin >> s;
    int32 q;
    cin >> q;
    while(q--){
        int32 k;
        cin >> k;
        int64 res = 0;
        int32 d = 0, m = 0, c = 0;
        int64 comb = 0;
        REP(i,n){
            if(i - k >= 0){
                if(s[i-k] == 'D'){
                    d--;
                    comb -= m;
                }else if(s[i-k] == 'M'){
                    m--;
                }else if(s[i-k] == 'C'){
                    c--;
                }
            }
            if(s[i] == 'D'){
                d++;
            }else if(s[i] == 'M'){
                m++;
                comb += d;
            }else if(s[i] == 'C'){
                c++;
                res += comb;
            }
            // cout << d << " " << m << " " << c << " " << comb << endl;
        }
        cout << res << endl;
    }
    return 0;
}