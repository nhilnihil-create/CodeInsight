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

int n ;
int h[200010];
int b[200010];
int dp[200010];

int32_t main(){   

fastio
// #ifndef ONLINE_JUDGE
// freopen("input.txt", "r", stdin);
// freopen("output.txt","w", stdout);
// #endif

cin>>n;
for(int i =1; i<=n ; i++)cin>>h[i];

for(int i =1; i<=n ; i++)cin>>b[i];


dp[1] =b[1];
int ans = dp[1];
map<int, int> mp;
mp.insert({h[1] , dp[1]});

for(int i =2 ; i<=n ; i++){

	dp[i] = b[i];
	auto it = mp.lower_bound(h[i]);

	if(it!=mp.begin()){
		it--;
		dp[i]+=it->ss;
	}

	mp.insert({h[i] , dp[i]});
	auto ub = mp.upper_bound(h[i]);

	while(ub != mp.end()  && ub->ss<=dp[i]){
		auto temp = ub;
		temp++;
		mp.erase(ub);
		ub = temp;
	}

	ans = max(ans , dp[i]);

}


cout<<ans;

return 0;
}
