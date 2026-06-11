#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<=n;i++)
typedef long long ll;

int main(){
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i,n) cin >> a[i];
	map<int,int> even;
	map<int,int> odd;
	rep(i,n){
		if(i % 2 == 0){
			even[a[i]]++;
		}else{
			odd[a[i]]++;
		}
	}
	vector<pair<int,int>> vp_odd;
	vector<pair<int,int>> vp_even;
	for(auto p: even){
		vp_even.emplace_back(p.second, p.first);
	}
	for(auto p: odd){
		vp_odd.emplace_back(p.second, p.first);
	}
	sort(vp_even.rbegin(),vp_even.rend());
	sort(vp_odd.rbegin(),vp_odd.rend());
	int ans = 0;
	if(vp_even[0].second == vp_odd[0].second){
		ans = min(n- vp_even[0].first - vp_odd[1].first, n- vp_even[1].first - vp_odd[0].first);
	}else{
		ans = n - vp_even[0].first - vp_odd[0].first;
	}
	cout << ans << endl;
    return 0;
}