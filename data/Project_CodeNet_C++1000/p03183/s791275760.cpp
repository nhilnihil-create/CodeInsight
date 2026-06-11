#include<bits/stdc++.h>
using namespace std;
//errichto
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

const int N=1e4+4;

ll dp[2*N];

struct Node{
	int w,s,v;
}arr[N];

bool comp(Node& n1,Node &n2){
	return n1.w+n1.s<n2.w+n2.s;
}

void solve(){
	int n;
	cin>>n;
	fr(i,0,n){
		cin>>arr[i].w>>arr[i].s>>arr[i].v;
	}
	sort(arr,arr+n,comp);
	fr(i,0,n){
		fri(j,arr[i].s,0){
			dp[arr[i].w + j]=max(dp[arr[i].w + j],dp[j]+arr[i].v);
		}
	}
	ll ans=*max_element(dp,dp+2*N);
	cout<<ans<<endl;
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