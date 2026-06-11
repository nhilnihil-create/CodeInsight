#include <bits/stdc++.h>
#define ll          long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define ff           first
#define ss           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;

// Most important thing in CP - Have Fun :)

const int maxn = 3000;
double dp[maxn][maxn];

void solve(){
	//write here
    int n;
    cin>>n;
    vector<double> p(n);
    rep(i,0,n)cin>>p[i];
    for (int j = 0 ; j<=n ; j++)dp[0][j] = 0;
    dp[0][0] = 1;
    for (int i = 1 ; i<=n ; i++)dp[i][0] = dp[i-1][0] *(1- p[i-1]);
    for (int i = 1 ; i<=n ; i++){
        for (int j = 1 ; j<=i ; j++){
            dp[i][j] = dp[i-1][j-1] * p[i-1] + dp[i-1][j]*(1 - p[i-1]);
        }
    }
    double ans = 0;
    for (int i = (n+1)/2 ; i<=n ; i++)ans+=dp[n][i];
    cout<<setprecision(10)<<ans<<endl;
    
}

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	//insert code
	
		solve();
	return 0;
}