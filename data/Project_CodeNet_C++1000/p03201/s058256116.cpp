#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll n;
	cin>>n;
	map<ll,ll>ch;
	for(ll i=0;i<n;i++){
		ll x;
		cin>>x;
		ch[x]++;
	}
	ll cnt=1;
	while(cnt<2'000'000'000){
		cnt*=2;
	}
	ll ans=0;
	while(ch.size()!=0){
		auto itr=ch.end();
		itr--;
		ll now=itr->first;
		ch[now]--;
		if(itr->second==0){
			ch.erase(now);
		}
		if(ch.size()==0){
			break;
		}
		while(now<cnt/2){
			cnt/=2;
		}
		auto ser=ch.find(cnt-now);
		if(ser!=ch.end()){
			ch[cnt-now]--;
			ans++;
			if(ser->second==0){
				ch.erase(cnt-now);
			}
		}
	}
	cout <<ans;

	// your code goes here
	return 0;
}