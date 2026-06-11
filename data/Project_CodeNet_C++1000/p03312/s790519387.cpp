#include<bits/stdc++.h>
using namespace std;

using ll = long long;
vector<ll> v;
int s[200005];
ll mn[200005], mx[200005];
ll mn2[200005], mx2[200005];

int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i ++) cin >> s[i];
	ll add = 0;
	ll sum = 0;
	for(int i = 0; i < n; i ++){
		add += s[i];
		sum += s[i];
		v.push_back(sum + add);
		int t = lower_bound(v.begin(), v.end(), add) - v.begin();
		if(t == 0){
			
		}
		else if(t == v.size()){
			t --;
		}
		else {
			if(abs(v[t - 1] - add) < abs(v[t] - add)) t --;
		}
		mn[i] = (sum + abs(v[t] - add)) / 2, mx[i] = (sum - abs(v[t] - add)) / 2;
		if(mn[i] > mx[i]) swap(mn[i], mx[i]);
	}
	v.clear();
	add = 0; sum = 0;
	ll ans = 1e18;
	for(int i = n - 1; i >= 0; i --){
		add += s[i];
		sum += s[i];
		v.push_back(sum + add);
		int t = lower_bound(v.begin(), v.end(), add) - v.begin();
		if(t == 0){
			
		}
		else if(t == v.size()){
			t --;
		}
		else {
			if(abs(v[t - 1] - add) < abs(v[t] - add)) t --;
		}
		mn2[i] = (sum + abs(v[t] - add)) / 2, mx2[i] = (sum - abs(v[t] - add)) / 2;
		if(mn2[i] > mx2[i]) swap(mn2[i], mx2[i]);
		ll rlt_max = max(mx2[i], mx[i - 1]);
		ll rlt_min = min(mn2[i], mn[i - 1]);
		ans = min(ans, rlt_max - rlt_min); 
	}
	cout << ans << '\n';
	
}
