#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

ll smallest2(ll a){
	ll rtn=1;
	while(rtn<=a) rtn*=2;
	return rtn;
}

int main(){
	int n;
	cin >> n;
	map<ll, int> cnt;
	for(int i=0; i<n; i++){
		ll a;
		cin >> a;
		cnt[a]++;
	}

	int ans=0;
	for(map<ll, int>::reverse_iterator it=cnt.rbegin(); ; it++){
		if(&it==0) continue;
		if(it==cnt.rend()) break;
		ll s=it->first, t=smallest2(s)-s;

		if(s==t){
			ll p=cnt[s]/2;
			ans+=p;
			cnt[s]-=p;
		}else{
			ll p=min(cnt[s], cnt[t]);
			ans+=p;
			cnt[s]-=p;
			cnt[t]-=p;
		}
	}

	cout << ans << endl;
	return 0;
}