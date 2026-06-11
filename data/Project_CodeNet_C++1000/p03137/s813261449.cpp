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

signed main(){
	ios_base::sync_with_stdio(0);
	int n,m;
	cin>>n>>m;
	vector<int> a(m),dist(m-1);
	for(int i=0;i<m;i++) cin>>a[i];
	sort(all(a));
	for(int i=0;i+1<m;i++) dist[i]=a[i+1]-a[i];
	sort(all(dist));
	int ans=0;
	for(int i=0;i<m-n;i++) ans+=dist[i];
	cout<<ans;
	re 0;
}