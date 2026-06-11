#include<bits/stdc++.h>
using ll = int_fast64_t;
using P = std::pair<ll,ll>;

int main(){
	int n;
	scanf("%d", &n);
	std::vector<P> ab(n);
	for(int i=0; i<n; i++) scanf("%ld %ld", &ab[i].first, &ab[i].second);
	std::sort(ab.begin(), ab.end(), [](P x, P y){
		return x.first+x.second > y.first+y.second;
	});
	
	ll ans = 0;
	for(int i=0; i<n; i++){
		if(i%2==0) ans += ab[i].first;
		else ans -= ab[i].second;
	}
	printf("%ld\n", ans);
	return 0;
}
