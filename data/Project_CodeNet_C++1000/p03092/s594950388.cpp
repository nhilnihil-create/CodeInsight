#include<bits/stdc++.h>
const int maxn = 5001;
typedef long long ll;
int p[maxn], n;
ll dp[maxn], a, b;
int main()
{
	std::cin >> n >> a >> b;
	for(int i = 1;i <= n;++i) std::cin >> p[i], dp[i] = (i - 1) * a;
	ll ans = 1e18;
	for(int i = 1;i <= n;++i) {
		ll s = 0; int min = 1e9;
		for(int j = i + 1;j <= n;++j) {
			if(p[i] < p[j] && p[j] < min) {
				min = p[j];
				dp[j] = std::min(dp[j], dp[i] + s);
			}
			s += p[j] < p[i] ? b : a;
		}
		ans = std::min(ans, dp[i] + (n - i) * b);
	}
	std::cout << ans << '\n';
}
