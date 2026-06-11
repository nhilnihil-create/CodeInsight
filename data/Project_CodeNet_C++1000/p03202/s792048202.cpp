#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

int n, a[200005];
int lt=1, rt, md, ans;

int f(int p) {
	int i, t;
	map<int,int> mp;
	if(p==1) {
		for(i=2; i<=n; i++) if(a[i] <= a[i-1]) return 0;
		return 1;
	}
	for(i=2; i<=n; i++) if(a[i] <= a[i-1]) {
		t = a[i];
		mp.erase(mp.upper_bound(t), mp.end());
		for(; t && mp[t]==p-1; t--) mp.erase(t);
		if(!t) return 0;
		else mp[t]++;
	}
	return 1;
}

int main() {
	cin >> n;
	for(int i=1; i<=n; i++) scanf("%d", &a[i]);
	rt = n;
	while(lt<=rt) {
		md = lt+rt >> 1;
		if(f(md)) ans = md, rt = md-1;
		else lt = md+1;
	}
	cout << ans;
	return 0;
}