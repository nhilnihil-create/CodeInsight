#include <bits/stdc++.h>
#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
int n;
vector<int> lst[100010];
int main() {
	scanf("%d", &n);
	int lo = 1, hi = n;
	while(lo < hi) {
		int mid = (lo + hi) / 2;
		if(1ll*mid*(mid+1)/2 < n) lo = mid + 1;
		else hi = mid;
	}
	if(lo*(lo+1)/2 != n) { puts("No"); return 0; }
	puts("Yes");
	printf("%d\n", lo + 1);
	int cur = 1;
	for(int i=1; i<=lo; i++) {
		for(int j=1; j<=i; j++) {
			lst[i+1].push_back(cur);
			lst[i-j+1].push_back(cur);
			cur++;
		}
	}

	for(int i=1; i<=lo+1; i++) {
		printf("%d ", sz(lst[i]));
		for(int j : lst[i]) printf("%d ", j);
		puts("");
	}
	return 0;
}