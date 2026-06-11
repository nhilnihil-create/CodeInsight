#include <bits/stdc++.h>

using namespace std;

#define int long long

int N;
int A[200010];
int ans;
multiset<int> ms;

signed main() {
	
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d", &A[i]);
	
	sort(A + 1, A + N + 1);
	
	for (int i = 1; i <= N; i++)
		ms.insert(A[i]);
	
	while (! ms.empty()) {
		int tmp = *ms.rbegin();
		int cnt = 1;
		ms.erase(ms.find(tmp));
		while (cnt <= tmp)
			cnt *= 2;
		int x = cnt - tmp;
		multiset<int>::iterator it = ms.find(x);
		if (it == ms.end()) continue;
		ms.erase(it);
		ans++;
	}
	
	printf("%d\n", ans);
	
	return 0;
	
}