#include <bits/stdc++.h>
#define pb push_back
#define int long long
#define mp make_pair
#define inf 1000000007
#define ll long long
using namespace std;
ll ls[114514],rs[114514];
signed main(){
	int n;
	cin>>n;
	vector<ll> l,r;
	for(int i=0;i<n;i++){
		int x,y;
		cin>>x>>y;
		l.pb(2*x);r.pb(-2*y);
	}
	sort(l.begin(),l.end(),greater<ll>());
	sort(r.begin(),r.end(),greater<ll>());
	ls[0] = l[0];rs[0]=r[0];
	for(int i=1;i<n;i++){
		ls[i] = ls[i-1] + l[i];
		rs[i] = rs[i-1] + r[i];
	}
	ll ans = 0;
	for(int i=0;i<=n;i++){
		ll tmp;
		if(i%2==0){
			tmp = ls[i/2-1]+rs[i/2-1];
		}
		else{
			tmp =  max(ls[i/2]+rs[i/2-1], ls[i/2-1]+rs[i/2]);
		}
		ans = max(ans,tmp);
	}
	cout<<ans<<endl;
	return 0;
}