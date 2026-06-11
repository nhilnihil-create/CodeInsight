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

char c[4] = {'L', 'D', 'U', 'R'};
int32 dy[4] = { 0, 1,-1, 0};
int32 dx[4] = {-1, 0, 0, 1};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int32 h,w,n;
    cin >> h >> w >> n;
    int32 sr, sc;
    cin >> sr >> sc;
    sr--;sc--;
    string s,t;
    cin >> s >> t;
    vector<vector<int32>> cnt(4, vector<int32>(n+1, 0));
    REP(i,n){
        REP(j,4){
            cnt[j][i+1] = cnt[j][i];
        }
        REP(j,4){
            if(s[i] == c[j]){
                cnt[j][i+1]++;
            }
            
        }
        REP(j,4){
            int32 nr = sr + cnt[j][i+1] * dy[j];
            int32 nc = sc + cnt[j][i+1] * dx[j];
            if(nr < 0 || h <= nr || nc < 0 || w <= nc){
                cout <<"NO\n";
                return 0;
            }
        }
        REP(j,4){
            if(t[i] == c[j]){
                cnt[3-j][i+1]--;
                int32 nr = sr + cnt[3-j][i+1] * dy[3-j];
                int32 nc = sc + cnt[3-j][i+1] * dx[3-j];
                if(nr < 0 || h <= nr || nc < 0 || w <= nc){
                    cnt[3-j][i+1]++;
                }
            }

        }
    }
    cout << "YES\n";
    return 0;
}