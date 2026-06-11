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
int n;
int ans,mx=-1;
signed main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	while(n--){
		int p;
		cin>>p;
		ans+=p;
		mx=max(mx,p);
	}
	ans-=mx/2;
	cout<<ans;
	re 0;
}