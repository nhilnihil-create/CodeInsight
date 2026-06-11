#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int,long long> a, pair<int,long long> b){
	return a.second > b.second;
}
int main() {
	int n,k;
	long long cnt = 0, num = 0;
	long long ans = 0, sz;
	cin >> n >> k;
	vector<pair<int,long long>> a(n);
	for(int i = 0; i < n; ++i) cin >> a[i].first >> a[i].second;
	sort(a.begin(), a.end(), cmp);
	map<int,int> mp;
	stack<pair<int,long long>> st;
	
	for(int i = 0; i < n; ++i){
		if(num < k){
			num++;
			cnt+= a[i].second;
			mp[a[i].first]++;
			if(mp[a[i].first] > 1) st.push(a[i]);
		}
		else{
			if(st.size() == 0) break;
			if(mp[a[i].first]) continue;
			cnt-= st.top().second;
			cnt+= a[i].second;
			st.pop();
			mp[a[i].first]++;
		}
		sz = mp.size();
		ans = max(ans, cnt + sz*sz);
	}
	cout << ans;
	return 0;
}