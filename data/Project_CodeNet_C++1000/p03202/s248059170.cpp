#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <map>
using namespace std;
typedef long long LL;

LL n,flg = 0;
LL s[500005];
LL stk[2][500005] = {0};

LL chk(LL x){
	LL tp = 0;
	for(LL i = 1;i <= n;i ++){
		if(s[i - 1] >= s[i]){
			while(stk[0][tp] > s[i]) tp --;
			LL now = s[i];
			while(1){
				if(stk[0][tp] != now || stk[1][tp] < x - 1){
					if(stk[0][tp] != now){ stk[0][++ tp] = now; stk[1][tp] = 0; }
					stk[1][tp] ++; break;
				}
				else{ tp --; now --; }
				if(now <= 0) return 0;
			}
		}
	}
	return 1;
}

int main(){
	cin >> n;
	for(LL i = 1;i <= n;i ++) cin >> s[i];
	for(LL i = 1;i < n;i ++) if(s[i] >= s[i + 1]) flg = 1;
	if(!flg){ cout << 1 << '\n'; return 0; }
	
	LL l = 2,r = n,mid,ans;
	while(l <= r){
		mid = (l + r) >> 1;
		if(chk(mid)){
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	cout << ans << '\n';
	return 0;
}