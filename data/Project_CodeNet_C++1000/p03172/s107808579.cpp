	#include<bits/stdc++.h>
	using namespace std;
	#define int long long
	#define ld long double
	#define FOR(i,a,b) for(int i = (a); i <= (b); ++i)
	#define FORD(i,a,b) for(int i = (a); i >= (b); --i)
	#define RI(i,n) FOR(i,1,(n))
	#define REP(i,n) FOR(i,0,(n)-1) 
	#define mp make_pair
	#define pb push_back
	#define st first
	#define nd second
	#define sz(w) (int) w.size() 
	#define inf 1e9+9
	#define MAX 1e5+5
	#define fast  ios_base::sync_with_stdio(false);  cin.tie(NULL);
	typedef vector<int> vi;
	typedef pair<int,int> pii; 

	int max(int a, int b){return a>b? a:b;}
	int min(int a, int b){return a<b? a:b;}
	const int MOD = 1e9+7;
 

	void helperi(int a[], int k, int n){
		int dp[k+1];
		// dp[i]: no of ways we used i candies so farA
		memset(dp,0, sizeof(dp));  
		dp[0]=1;
		int prefix[k+1]; memset(prefix, 0, sizeof(prefix));
		 
		for(int i=1;i<=n;i++){
			prefix[0]=dp[0];
			dp[0]=0;
			for(int j=1;j<=k;j++)
				prefix[j]=(prefix[j-1]+dp[j])%MOD;

			for(int j=k;j>=0;j--){  
				int sum = prefix[j];
				int l = j - min(a[i-1], j);
				if(l!=0)
					sum-=prefix[l-1];
				dp[j]=sum%MOD;
			}
		}
	
		cout << (dp[k]+MOD)%MOD << endl;
	}


	void solve(){
		
		int n, k; 
		cin >> n >> k;
		int a[n];
		for(int i=0;i<n;i++)
			cin>>a[i];
		//cout << "DONE "
		helperi(a, k, n);
	}


	int32_t main(){ 
		fast
		int t;
		// cin>>t;
		t=1;
		while(t--){
			solve();
		}
	}