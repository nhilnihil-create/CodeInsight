#include <bits/stdc++.h>
#define maxn 102333 
using namespace std;
int a[maxn], b[maxn];
vector< pair<int, int> > V;
int main() {
	int n, H, cur = 0, ans = 0;
	scanf("%d%d", &n, &H);
	for(int i = 1; i <= n; ++i) {
		scanf("%d%d", a + i, b + i);
		V.push_back(make_pair(a[i], 1));
		V.push_back(make_pair(b[i], 0));
	}
	sort(V.begin(), V.end());
	reverse(V.begin(), V.end());
	for(auto it = V.begin(); it != V.end() && cur < H; ++it) {
		if(it->second) {
			ans += (H - cur - 1) / (it->first) + 1;
			break;
		} else {
			cur += it->first;
			++ans;
		}
	}
	printf("%d", ans);
	return 0;
}