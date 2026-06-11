#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vll vector<ll>
#define vpii vector<pair<int,int>>
#define vpll vector<pair<ll,ll>>
#define fr(i,k,n) for (int i = k; i < n; ++i)
#define fri(i,k,n) for (int i = k; i >= n; --i)
#define INF (int)1e9
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define all(arr) arr.begin(),arr.end()

void boost(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void solve(){
	int n,k;
	cin>>n>>k;
	int arr[n];
	fr(i,0,n)
	cin>>arr[i];
	vector<bool> dp(k+1,false);
	fr(i,1,k+1)
	fr(j,0,n){
		if(i<arr[j])
			break;
		if(dp[i-arr[j]]==false)
			dp[i]=true;
	}
	cout<<(dp[k]?"First":"Second")<<endl;
	return;
}

int main()
{
	boost();
	
	int tc=1;
	//cin>>tc;
	while(tc--)
		solve();
	return 0;
}