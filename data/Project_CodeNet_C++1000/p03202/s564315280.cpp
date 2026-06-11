#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

int n, a[MAXN];

bool can(int c){
	map <int, int> mp;
	for(int i = 0; i < n; i++){
		if(a[i] <= a[i - 1]){
			auto d = mp.lower_bound(a[i]);
			while(d != mp.end()){
				auto nxt = next(d);
				mp.erase(d);
				d = nxt;
			}
			
			int x = a[i] - 1;
			while(true){
				if(x < 0)return false;
				
				if(mp[x] + 1 < c){
					mp[x]++;
					break;
				}else{
					mp.erase(x);
					x--;
				}
			}
		}
	}
	return true;
}
int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	
	bool ok = true;
	for(int i = 1; i < n; i++){
		if(a[i] <= a[i - 1]){
			ok = false;
			break;
		}
	}
	
	if(ok){
		printf("1\n");
		return 0;
	}
	
	int L = 2, R = n;
	while(L < R){
		int mid = (L + R) / 2;
		if(can(mid))R = mid;
		else L = mid + 1;
	}
	printf("%d\n", L);
	
	return 0;
}
