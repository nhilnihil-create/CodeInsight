#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll n;
	cin>>n;
	map<ll,ll>a,b;
	ll maxa=0,maxb=0;
	ll nowa=-1,nowb=-1;
	for(ll i=0;i<n;i++){
		ll now;
		cin>>now;
		if(i%2==1){
			a[now]++;
			if(maxa<=a[now]){
				nowa=now;
				maxa=a[now];				
			}
		}
		else{
			b[now]++;
			if(maxb<=b[now]){
				nowb=now;
				maxb=b[now];				
			}
		}
	}
	if(nowa!=nowb){
		cout << n-maxa-maxb;
//		cout << 0;
	}
	else{
		ll ans=inf;
		ll cnt=0;
		for(auto itr=a.begin();itr!=a.end();itr++){
			ll val=itr->second;
			ll num=itr->first;
			if(val>=cnt&&num!=nowb){
				cnt=val;
			}
		}
		ans=min(ans,n-cnt-maxb);
	//	cout <<ans<<cnt<<nowb<<nowa<<endl;
		cnt=0;
		for(auto itr=b.begin();itr!=b.end();itr++){
			ll val=itr->second;
			ll num=itr->first;
			if(val>=cnt&&num!=nowa){
				cnt=val;
			}
		}
		ans=min(ans,n-cnt-maxa);
		cout <<ans;
	}
	// your code goes here
	return 0;
}