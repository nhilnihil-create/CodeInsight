#include<bits/stdc++.h>
#define int long long
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define sz(a) a.size()
#define re return 
#define MP make_pair
#define pb push_back
#define pii pair<int,int>
#define se second
#define fi first
using namespace std;
int n,k;
int ans=1e18;
signed main(){
	ios_base::sync_with_stdio(0);
	cin>>n>>k;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	sort(all(a));
	for(int i=0;i+k<=n;i++) ans=min(ans,a[i+k-1]-a[i]);
	cout<<ans;
	re 0;
}