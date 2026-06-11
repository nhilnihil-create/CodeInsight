#include <bits/stdc++.h>
#define FOR(i, n) for (long long i = 0; i < (n); ++i)
#define pb push_back
#define int long long
#define debug(x) std::cout << #x << ": " << x << '\n';
typedef long long ll;
const int N = 2e5 + 10;
std::vector<int> a[N];

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int h, w, n;
    std::cin >> h >> w >> n;
    FOR(i, n) {
    	int x, y;
    	std::cin >> x >> y;
    	--x; --y;
    	a[y].push_back(x);
    }
    FOR(i, w + 10) {
    	a[i].push_back(h);
    	std::sort(a[i].begin(), a[i].end());
    }
    int minAnsw = 1e9, curDown = 0;
    FOR(i, w) {
    	auto it = std::lower_bound(a[i].begin(), a[i].end(), curDown);
    	minAnsw = std::min(minAnsw, curDown + (*it - curDown));
    	curDown++;
    	auto it2 = std::lower_bound(a[i + 1].begin(), a[i + 1].end(), curDown);
    	while (it2 < a[i + 1].end() && *it2 == curDown) {
    		curDown++;
    		++it2;
    	}
    	if (curDown >= h) {
    		break;
    	}
    }
    std::cout << minAnsw;
}