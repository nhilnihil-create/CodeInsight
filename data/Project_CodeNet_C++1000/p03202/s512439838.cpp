#include<bits/stdc++.h>
using namespace std;
const int maxn = 200000 + 10;
//const int maxn = 1000 + 10;

int n, a[maxn];
map<int,int> mp;

inline int check(int k) {
  mp.clear();
	for(int i = 2;i <= n;i ++) {
	  if(a[i - 1] >= a[i]) {
		  while(!mp.empty()) {
			  int x = (mp.rbegin())->first;
				if(x > a[i]) mp.erase(mp.find(x));
				else break;
			}
			int j;
			for(j = a[i];j >= 1;j --) {
			  mp[j] ++;
				if(mp[j] == k) mp[j] = 0;
				else break;
			}
			if(!j) return 0;
		}
	}
	return 1;
}

int main() {
  scanf("%d", &n);
	for(int i = 1;i <= n;i ++) scanf("%d", &a[i]);
	int flag = 0;
	for(int i = 2;i <= n;i ++) if(a[i] <= a[i - 1]) flag = 1;
	if(!flag) {
	  puts("1");
		return 0;
	}
	int L = 2, R = n << 1, ans = n << 1;
	while(L <= R) {
	  int mid = (L + R) >> 1;
		if(check(mid)) R = mid - 1, ans = mid;
		else L = mid + 1;
	}
	printf("%d\n", ans);
  return 0;
}
