#include <bits/stdc++.h>
using namespace std;
#define REP(i,a) for(int i = 0; i < (a); i++)
#define ALL(a) (a).begin(),(a).end()
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const long long LINF = 1e18;
const long long MOD = 1e9 + 7;

signed main(){
    int n;
    cin >> n;
    string s[n];
    REP(i,n){
        cin >> s[i];
    }
    int ans = 0;
    for(int a = 0; a < n; a++){
        char t[n][n];
        REP(i,n){
            REP(j,n){
                t[i][j] = s[(i + a) % n][j];
            }
        }
        REP(i,n){
            REP(j,n){
                if(t[i][j] != t[j][i]) goto no;
            }
        }
        ans++;
        no:;
    }
    cout << ans * n << endl;
    return 0;
}