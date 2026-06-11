#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;

#define fr first
#define sc second

int main(){
	static ll n;
	static ll d[100010];
	scanf("%lld",&n);
	for(int i = 1 ; i <= n ; i ++){
		scanf("%lld",&d[i]);
	}
	
	vector<P> vec;
	for(int i = 1 ; i <= n ; i ++){
		vec.push_back(P(d[i],i));
	}
	sort(vec.begin(),vec.end());
	reverse(vec.begin(),vec.end());
	
	static ll cnt[100010];
	static ll dp[100010];
	for(int i = 1 ; i <= n ; i ++){
		cnt[i] = 1;
		dp[i] = 0;
	}
	
	map<ll,ll> id;
	for(int i = 1 ; i <= n ; i ++){
		id[d[i]] = i;
	}
	
	vector<P> ans;
	for(int i = 1 ; i <= n ; i ++){
		P p = vec[i-1];
		//cout << p.fr << " " << p.sc << endl;
		if(cnt[p.sc]*2 >= n)continue;
		ll nx = d[p.sc]-(n-cnt[p.sc])+cnt[p.sc];
		if(id.find(nx) == id.end()){
			puts("-1");
			return 0;
		}
		else {
			ans.push_back(P(p.sc,id[nx]));
			cnt[id[nx]] += cnt[p.sc];
			dp[id[nx]] += dp[p.sc];
			dp[id[nx]] += cnt[p.sc];
		}
	}
	if(n%2 == 0){
		if(ans.size() != n-1){
			if(vec[n-2].fr != vec[n-1].fr){
				puts("-1");
				return 0;
			}
			ans.push_back(P(vec[n-2].sc,vec[n-1].sc));
			if(vec[n-1].fr != dp[vec[n-1].sc]+dp[vec[n-2].sc]+n/2){
				puts("-1");
				return 0;
			}
		}
		else {
			if(vec[n-1].fr != dp[vec[n-1].sc]){
				puts("-1");
				return 0;
			}
		}
	}
	else {
		if(vec[n-1].fr != dp[vec[n-1].sc]){
			puts("-1");
			return 0;
		}
	}
	
	/*for(int i = 1 ; i <= n ; i ++){
		if(dp[i] != d[i]){
			puts("-1");
			return 0;
		}
	}*/
	
	if(ans.size() < n-1){
		puts("-1");
		return 0;
	}
	for(int i = 0 ; i < ans.size() ; i ++){
		printf("%d %d\n",ans[i].fr,ans[i].sc);
	}
}
