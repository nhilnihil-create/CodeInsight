#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FAST ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ALL(a) a.begin(), a.end()
#define RALL(a) a.rbegin(), a.rend()
#define pb push_back
#define MOD 1000000007
#define sz5 100005
#define sz6 1000005
#define UP upper_bound
#define LB lower_bound
#define F first
#define S second
#define PI pair<int,int>
#define PL pair<ll,ll>
#define VI vector<int>
#define VL vector<ll>

double p[3003];

int main() {
	ll n,la,lb;
	cin>>n;
	vector<vector<double>> dp(n+5, vector<double>(n+5, 0.0));

	for(la=1;la<=n;la++)
		cin>>p[la];

	// dp[a][b] - a coins, n heads

	dp[0][0]=1.0;
	for(la=1;la<=n;la++){
		for(lb=0;lb<=la;lb++){
			if(lb>0)
				dp[la][lb] += dp[la-1][lb-1]*p[la];
			dp[la][lb] += dp[la-1][lb]*(1-p[la]);
		}
	}

	double ans=0.0;
	for(la=1;la<=n;la++){
		int head=la, tail=n-head;

		if(head>tail)
			ans+=dp[n][la];
	}

	printf("%.10lf\n",ans);

	return 0;
}