#include <bits/stdc++.h>
using namespace std;
const int maxn = 234566;
int a[maxn], n;
bool check(int m){
	struct interval { int l, r, v; };
	vector<interval> in;
       	in.push_back({0, a[0], 0});
	for(int i = 1; i < n; i++){
		if(a[i] > a[i - 1]){
			in.push_back({a[i - 1], a[i], 0});
			continue;
		}
		while(!in.empty() && in.back().l >= a[i]) in.pop_back();
	       	in.back().r = a[i];	
		while(!in.empty() && in.back().v == m - 1) in.pop_back();
		if(in.empty()) return false;
		interval cur = in.back(); in.pop_back();
		if(cur.l != cur.r - 1) in.push_back({cur.l, cur.r - 1, cur.v});
		in.push_back({cur.r - 1, cur.r, cur.v + 1});
	    	if(cur.r != a[i]) in.push_back({cur.r, a[i], 0});
	}
	return true;
}
int main(){
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	int lo = 1, hi = 3 * n, ans = 0;
	while(lo <= hi){
		int mid = (lo + hi)>>1;
		if(check(mid)) hi = mid - 1, ans = mid;
		else lo = mid + 1;
	}
	return !printf("%d\n", ans);
}
