#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

int n, a[MAXN];

int main(){
	scanf("%d", &n);
	
	map <int, int> mp;
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		mp[a[i]]++;
	}
	
	int res = 0;
	for(int i = (1 << 30); i >= 2; i >>= 1){
		for(auto &d : mp){
			if(d.first == i - d.first){
				res += d.second / 2;
				d.second %= 2;
			}else{
				if(mp.count(i - d.first)){
					int mn = min(d.second, mp[i - d.first]);
					res += mn;
					d.second -= mn;
					mp[i - d.first] -= mn;
				}
			}
		}
	}
	printf("%d\n", res);
	
	return 0;
}
