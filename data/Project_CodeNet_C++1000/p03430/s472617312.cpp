#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007, INF=mod*mod*3LL;
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

void chmax(int &a, int b){a = max(a, b);}
int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    string s;
    int m;
    cin >> s >> m;
    int n = s.length();
    s = "#" + s;
    vector<vector<vector<int> > > dp(n+1, vector<vector<int> > (n+2, vector<int> (m+1, 0)));
    int ans = 0;
    for(int i=1;i<=n;i++){
    	for(int j=n;j>=i;j--){
    		for(int k=0;k<=m;k++){
    			chmax(dp[i][j][k], dp[i][j+1][k]);
    			chmax(dp[i][j][k], dp[i-1][j][k]);
    		}
    		if(s[i] == s[j]){
    			for(int k=0;k<=m;k++){
    				if(i == j) chmax(dp[i][j][k], dp[i-1][j+1][k] + 1);
    				else chmax(dp[i][j][k], dp[i-1][j+1][k] + 2);
    				chmax(ans, dp[i][j][k]);
    			}
    		}else{
    			for(int k=0;k<m;k++){
    				if(i == j) chmax(dp[i][j][k+1], dp[i-1][j+1][k] + 1);
    				else chmax(dp[i][j][k+1], dp[i-1][j+1][k] + 2);
    				chmax(ans, dp[i][j][k+1]);
    			}
    		}
    	}
    }
    cout << ans << endl;
    return 0;
}
