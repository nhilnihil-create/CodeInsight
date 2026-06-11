#include <bits/stdc++.h>
#ifdef LOCAL
#include <pprint.hpp>
#endif
#define endl "\n";
#define pb push_back
#define md 1000000007
#define ll long long int
#define all(v) v.begin(),v.end()
ll power(ll a,ll b){ll z=1;while(b){if(b&1){z*=a;z%=md;}a*=a;a%=md;b/=2;}return z%md;}
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n;
double a[3100],ans=0.0,p;
int main(){
	//You need to change array size!
	#ifndef LOCAL
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	#endif 
	
	a[0]=1.0;
	cin>>n;
	for(int i=0;i<n;++i)
	{
		cin>>p;
		for(int j=i+1;j>=0;--j){
			a[j] = (j==0 ? 0 : a[j-1]*p) + a[j]*(1.0-p);
		}
	}
	for(int i=0;i<=n;++i){
		if(i>(n-i))
			ans+=a[i];
	}
	cout<<fixed<<setprecision(12)<<ans;
	
	return 0;	
}