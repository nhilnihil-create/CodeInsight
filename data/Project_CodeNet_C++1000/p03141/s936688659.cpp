#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007
 
ll a[100010],b[100010];
int main() {
	ll n;
	cin>>n;
	vector<pair<ll,ll>>c;
	for(ll i=0;i<n;i++){
		ll x,y;
		cin>>x>>y;
		a[i]=x;
		b[i]=y;
		c.push_back(make_pair(x+y,i));
	}
	sort(c.begin(),c.end());
	reverse(c.begin(),c.end());
	ll ans=0;
	for(ll i=0;i<n;i++){
		ll now=c[i].second;
		if(i%2==0){
			ans+=a[now];
		}
		else{
			ans-=b[now];
		}
	}
	cout <<ans;
	// your code goes here
	return 0;
}