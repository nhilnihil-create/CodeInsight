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
    string s;
    cin >> s;
    int n = s.size();
    int ans = n;
    REP(i,n - 1){
        if(s[i] != s[i + 1]){
            ans = min(ans, max(i + 1, n - (i + 1)));
        }
    }
    cout << ans << endl;
    return 0;
}