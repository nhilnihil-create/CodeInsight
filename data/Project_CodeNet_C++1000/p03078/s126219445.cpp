#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll a[1010],b[1010],c[1010];
int main(){
	ll x,y,z,k;
	cin>>x>>y>>z>>k;
	for(int i=0;i<x;i++)cin>>a[i];
	for(int i=0;i<y;i++)cin>>b[i];
	for(int i=0;i<z;i++)cin>>c[i];
	vector<ll>v,w;
	for(int i=0;i<x;i++)for(int j=0;j<y;j++)v.push_back(-(a[i]+b[j]));
	sort(v.begin(),v.end());
	for(int i=0;i<min(x*y,k);i++)for(int j=0;j<z;j++)w.push_back(-(-v[i]+c[j]));
	sort(w.begin(),w.end());
	for(int i=0;i<k;i++)cout<<-w[i]<<endl;
	return 0;
}
