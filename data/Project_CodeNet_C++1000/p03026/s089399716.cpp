#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007 

vector<vector<ll>>a(10002);
vector<ll>b;ll p;
ll c[10002],ans;
void dep(ll now){
	for(ll i=0;i<a[now].size();i++){
		ll next=a[now][i];
		if(c[next]!=0){
			continue;
		}
		c[next]=b[p];
		p++;
		ans+=min(c[now],c[next]);
		dep(next);
	}
}
int main() {
	ll n;
	cin>>n;
	for(ll i=0;i<n-1;i++){
		ll x,y;
		cin>>x>>y;
		x--;y--;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	for(ll i=0;i<n;i++){
		ll x;
		cin>>x;
		b.push_back(x);
	}
	sort(b.begin(),b.end());
	reverse(b.begin(),b.end());
	c[0]=b[0];
	p++;
	dep(0);
	cout << ans<<endl;
	for(ll i=0;i<n;i++){
		cout << c[i]<<" ";
	}
	// your code goes here
	return 0;
}