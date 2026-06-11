#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL) ;
#define MOD 1000000007
#define int long long 
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpii vector<pair<int,int>>
#define ff first
#define ss second
#define INF (1LL<<61)

using namespace std;


int n , k;
int a[110];
int dp[100010];

int32_t main(){   

fastio
// #ifndef ONLINE_JUDGE
// freopen("input.txt", "r", stdin);
// freopen("output.txt","w", stdout);
// #endif

cin>>n>>k;
for(int i =1; i<=n ; i++)cin>>a[i];

for(int i =1 ; i<=k ; i++){

	for(int j =1; j<=n ; j++){
		if(i>=a[j])
		if(dp[i-a[j]]==0)dp[i]=1;
	}
}

if(dp[k])cout<<"First\n";
else cout<<"Second\n";


return 0;
}
