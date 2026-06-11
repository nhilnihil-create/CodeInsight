#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl "\n"
#define pb push_back
#define mod 1000000007
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int dx8[]={1,-1,0,0,1,1,-1,-1};
int dy8[]={0,0,1,-1,1,-1,1,-1};

ll binexp(ll a, ll b, ll m) {
	a %= m;
	ll res = 1;
	while (b > 0) {
		if (b & 1)
			res = res * a % m;
		a = a * a % m;
		b >>= 1;
	}
	return res;
}
ll modinvfermat(ll a, ll m)
{
	return binexp(a, m - 2, m);
}
void task(bool flag)
{
	if (flag)
		cout << "YES\n";
	else
		cout << "NO\n";
}
ll lcm(ll a, ll b)
{
	return ((1LL * a * b) / (__gcd(a, b)));
}

 // void dfs(ll node){
 // 	vis[node]=1;
 // 	res.pb(node);
 //    vector<ll> ans;


 // 	for(auto i:v[node]){
 // 		if(!vis[i]){
 // 			ans.pb(i);

 // 		}
 // 	}
 // 	sort(ans.begin(),ans.end());

 // 	for(auto i:ans){
 // 		if(!vis[i])
 // 			dfs(i);
 // 	}




 // }
bool sortbysec(const pair<int,int> &a, 
              const pair<int,int> &b) 
{ 
    return (a.second < b.second); 
}
bool sortbyme(const pair<int,int> &a, 
              const pair<int,int> &b){
	return (a.first+a.second > b.first+b.second);

}
ll dp[1000000];
ll tot=INT_MAX;


ll dmch(vector<ll> a,ll ind,ll x,ll n){



	if(ind>=n-1)return 0;
	else if(dp[ind]!=-1){
		return dp[ind];

	}
	else{
		ll ans=INT_MAX;
		for(ll i=1;i<=2;i++)
			if(i+ind<n)
			{
				ans=min(abs(a[ind]-a[ind+i])+dmch(a,ind+i,x,n),ans);

			}
			else
				break;

		// ans=min(a[ind]+dmch(a,ind+1LL,x,n),min(a[ind]+dmch(a,ind+2ll,x,n)+x,a[ind]+x*2+dmch(a,ind+3ll,x,n)));
		dp[ind]=ans;
		return dp[ind];

	}
}
void solve(){
	int n;
	cin >> n;
	int arr[n];
	for(int& i : arr) cin >> i;
	int DP[n];
	DP[n-1] = 0;
	for(int i = n-2; i >=0; --i){
		DP[i] = DP[i+1] + abs(arr[i] - arr[i+1]);
		if(i+2 < n) DP[i] = min(DP[i], DP[i+2] + abs(arr[i] - arr[i+2]));
	}
	cout << DP[0] << endl;





return;
}



int main()
{  
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
    fast;
    

    ll t;
    t=1;
    //cin>>t;
    while(t--){
    	solve();
    }
    
   
  



#ifndef ONLINE_JUDGE
	cout << "\nTime Elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " sec\n";
#endif
return 0;
}