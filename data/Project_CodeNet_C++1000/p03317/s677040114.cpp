#include<bits/stdc++.h>
#define ll long long
#define all(a) a.begin(),a.end()
#define sz(a) a.size()
#define re return 
#define MP make_pair
#define pb push_back
#define pii pair<int,int>
#define se second
#define fi first
using namespace std;
int n,k;
int ans;
signed main(){
	ios_base::sync_with_stdio(0);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
	}
	n-=k,ans++;
	if(n%(k-1)) ans+=n/(k-1)+1;
	else ans+=n/(k-1);
	cout<<ans; 
	re 0;
}