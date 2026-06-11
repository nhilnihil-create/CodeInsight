#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	int n, k;
	cin>>n>>k;
	vector<pair<int, int> > arr(n);
	for(auto &x : arr){
		cin>>x.second>>x.first;
		x.second -= 1;
	}
	sort(arr.rbegin(), arr.rend());
	vector<int> mask(n, 0);
	map<int, int> mp;
	ll sum = 0, cnt = 0;
	for(int i = 0; i < k; i++){
		if(mask[arr[i].second]){
			mp[arr[i].first]++;
		}else{
			mask[arr[i].second] = 1;
			cnt++;
		}
		sum += arr[i].first;
	}
	ll ans = sum + cnt*cnt;
	for(int i = k; i < n; i++){
		if(cnt == k)break;
		if(mask[arr[i].second])continue;
		mask[arr[i].second] = 1;
		int val = (*mp.begin()).first;
		mp[val]--; if(mp[val] == 0)mp.erase(val);
		sum += arr[i].first - val; cnt++;
		ans = max(ans, sum + cnt*cnt);
	}
	cout<<ans<<endl;
}