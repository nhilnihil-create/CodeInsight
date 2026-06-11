/********************************************
 *Author*        :ZZZZone
 *Created Time*  : 六  4/ 7 20:31:14 2018
 * Ended  Time*  : 六  4/ 7 22:11:25 2018
*********************************************/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <stack>
using namespace std;
#define debug(x) std::cerr << #x << " = " << (x) << std::endl
typedef pair<int, int> PII;
typedef long long LL;
typedef unsigned long long ULL;

inline void OPEN(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

LL a, b, sum;

bool check(LL mid){
	if(mid * mid <= sum) return true;
	return false;
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T--){
		scanf("%lld %lld", &a, &b);
		sum = a * b;
		sum--;
		LL res = 0;
		LL l = 1LL, r = 1 << 30, mid, ans = 1LL;
		while(l <= r){
			mid = (l + r) >> 1;
			if(check(mid)) l = mid + 1, ans = mid;
			else r = mid - 1;
		}
		if(ans * (ans + 1LL) <= sum){
			if(ans >= min(a, b)) res = 2LL * ans - 1;
			else res = 2LL * ans;
		}
		if(ans * (ans + 1LL) > sum){
			if(ans >= min(a, b)) res = 2LL * ans - 2;
			else res = 2LL * ans - 1;
		}
		printf("%lld\n", res);
	}
    return 0;
}
