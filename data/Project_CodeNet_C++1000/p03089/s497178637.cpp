#include <iostream>
#include <algorithm>
#include <vector>
#define flush fflush(stdout)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<P, P> PP;
typedef pair<ll, ll> Pl;
const int mod = (int)1e9 + 7, INF = (int)1e9;
const int di[4] = { 1,0,-1,0 }, dj[4] = { 0,1,0,-1 };


int main(void) {
	int n, i, bin;
	vector<int> b, ans;
	bool end;

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &bin);
		b.push_back(bin);
	}

	end = false;
	while (!end && !b.empty()) {
		end = true;
		for (i = b.size() - 1; i >= 0; i--) {
			if (b[i] == i + 1) {
				ans.push_back(b[i]);
				b.erase(b.begin() + i);
				end = false;
				break;
			}
		}
	}

	if (b.empty()) {
		for (i = n - 1; i >= 0; i--) {
			printf("%d\n", ans[i]);
		}
	}
	else {
		printf("-1\n");
	}

	return 0;
}