#include <bits/stdc++.h>
using namespace std;
#define REP(i,a) for(int i = 0; i < (a); i++)
#define ALL(a) (a).begin(),(a).end()
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const long long LINF = 1e18;
const long long MOD = 1e9 + 7;

int d[] = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};

signed main(){
    int n,m;
    cin >> n >> m;
    bool use[10] = {};
    REP(i,m){
        int a;
        cin >> a;
        use[a] = true;
    }
    vector<int> dp(n + 1, -INF);
    int prev[n + 1];
    dp[0] = 0;
    for(int i = 0; i <= n; i++){
        for(int j = 9; j >= 1; j--){
            if(!use[j]) continue;
            if(i - d[j] < 0) continue;
            if(dp[i - d[j]] + 1 > dp[i]){
                dp[i] = dp[i - d[j]] + 1;
                prev[i] = j;
            }
        }
    }
    string ans;
    int i = n;
    while(i != 0){
        ans.push_back('0' + prev[i]);
        i -= d[prev[i]];
    }
    cout << ans << endl;
    return 0;
}