#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <bitset>
using namespace std;
typedef long long LL;

LL n,tot = 0;
LL a[5005];
bitset<4000005> dp;

int main(){
    ios::sync_with_stdio(false);
	cin >> n;
	for(LL i = 1;i <= n;i ++){
		cin >> a[i];
		tot += a[i];
	}
	dp[0] = 1;
	for(LL i = 1;i <= n;i ++) dp |= (dp << a[i]);
	for(LL i = (tot + 1) >> 1;i <= tot;i ++){
		if(dp[i]){
			cout << i << endl;
			break;
		}
	}
	return 0;
} 