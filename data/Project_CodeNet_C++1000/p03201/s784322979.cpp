/*
	problem: 
	
	
*/

#include<bits/stdc++.h>
/*
#pragma GCC optamize("O2")
#pragma G++ optamize("O2")
*/
using namespace std;
const long long maxn = 0x3f3f3f3f;
typedef long long LL;

LL mi[31];
LL N;
LL a[200100];
map <LL, LL> mp;

int main() {
	
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	
	LL i, j, k;
    mi[0] = 1;
    for (i = 1; i <= 30; ++ i) mi[i] = (mi[i - 1] << 1);
    scanf("%lld", &N);
    for (i = 1; i <= N; ++ i) {
        scanf("%lld", &a[i]);
        ++ mp[a[i]];
    }
    sort(a + 1, a + N + 1);
    j = 30;
    LL ans = 0;
    for (i = N; i >= 1; -- i) {
        if (!mp[a[i]]) continue;
        while (mi[j] > (a[i] << 1) && j >= 0) -- j;
        LL x;
        if (a[i] != mi[j] - a[i]) {
            x = min(mp[a[i]], mp[mi[j] - a[i]]);
        }
        else {
            x = mp[a[i]] / 2;
        }
        mp[a[i]] -= x;
        mp[mi[j] - a[i]] -= x;
        ans += x;
    }
    printf("%lld\n", ans);
	
	return 0;
}
/*
3
1 2 3
5
3 11 14 5 13
*/ 
