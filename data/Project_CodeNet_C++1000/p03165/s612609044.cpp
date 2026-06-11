#include <bits/stdc++.h>
 
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long int
#define pb push_back
#define MOD 1000000007
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define read(a, n) for(ll i = 0;i<n;i++) cin>>a[i];
#define debug1(x) cout<<#x<<" "<<x<<endl;
#define debug2(x,y) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;
#define debug3(x,y,z) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define FileIO freopen("input.txt","r",stdin);freopen("output.txt","w",stdout)
const int INF = 1e9 + 5;

void solve() {
	string s, t;
	cin>>s>>t;
	
	int n = s.size();
	int m = t.size();
	
	int dp[m+1][n+1];
	memset(dp, 0, sizeof(dp));

	for(int i = 1;i<=m;i++) {
		//int f = 1;
		for(int j = 1;j<=n;j++) {
			if(t[i-1] == s[j-1]) {
				dp[i][j] = dp[i-1][j-1] + 1;
				//f = 0;
			}
			else {
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	
	string ans = "";
	
	int i = m, j = n;
	
	while(i > 0 && j > 0){
		if(t[i-1] == s[j-1]) {
			ans = t[i-1] + ans;
			i--;
			j--;
		}
		else {
			if(dp[i-1][j] > dp[i][j-1]) {
				i--;
			}
			else j--;
		}
	}
	//debug1(dp[m][n]);
	cout<<ans<<"\n";
}

int main()
{
	fastio;
	
	int T = 1;
	//cin>>T;
	//int tc = 1; 
	while(T--) {
		//cout<<"Case #"<<tc<<": ";
		solve();
		//tc++;
	}	
	return 0;
}
