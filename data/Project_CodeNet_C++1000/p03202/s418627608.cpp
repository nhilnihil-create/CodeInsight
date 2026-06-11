#include<bits/stdc++.h>
int a[200200],n;
inline bool check(int k){
	std::map<int,int> map;
	for(int i = 1;i <= n;++i) if(a[i] <= a[i - 1]){
		while(map.size() && map.rbegin() -> first > a[i - 1]) map.erase(--map.end());
		int now = a[i];
		for(;now > 0 && ++map[now] == k;--now) map[now] = 0;
		if(now <= 0) return 0;
	}
	return 1;
}
int main(){
	std::ios::sync_with_stdio(false),std::cin.tie(0);
	std::cin >> n; int flg = 1;
	for(int i = 1;i <= n;++i) std::cin >> a[i],flg &= a[i] > a[i - 1];
	if(flg) return std::cout << 1 << '\n',0;
	int l = 1, r = n;
	for(;l + 1 != r;){
		int mid = l + r >> 1;
		if(check(mid)) r = mid;
		else l = mid;
	}
	std::cout << r << '\n';
}
