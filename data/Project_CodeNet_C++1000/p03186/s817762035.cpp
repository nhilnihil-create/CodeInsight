#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define fi first
#define se second
int main(){
	ll a,b,c; cin>>a>>b>>c;
	ll x=min(a,c);
	ll ans=0;
	ans+=x;
	a-=x;
	c-=x;
	x=min(c,b);
	ans+=2*x;
	c-=x;
	b-=x;
	if(c>0) ans++;
	ans+=max((ll)0,b);
	cout<<ans;
}
