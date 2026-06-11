#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a, b, c, d;
bool solve(__int128 a, __int128 b, __int128 c, __int128 d) {
    __int128 gcd = __gcd(b, d);
    __int128 res = ((c-a)/gcd+1)*gcd;
    return res < b-a;
}
int main() {
	int t; scanf("%d", &t);
	while (t--) {
        scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
        if (a<b || a%b > c || c+d < b || b > d)puts("No");
        else if (c >= b) puts("Yes");
        else if (solve(a%b, b, c, d%b)) puts("No");
        else puts("Yes");
	}
}
