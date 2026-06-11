#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define per(i, a, b) for(register int i = a; i >= b; i--)
typedef long long LL;
const LL mod = 1e9 + 7;
const int N = 3e5 + 5;

LL n, cur, s = 1;
int ans;

int main() {
	cin>>n;
	cur = 0;
	while(cur*10 + 9 <= n) {
		cur = cur*10 + 9;
		ans += 9;
		s *= 10;
	}
	n -= cur;
	ans += n/s;
	cout<<ans<<endl;
}