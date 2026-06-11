#include <cstdio>
#include <algorithm>
#include <stack>
using namespace std;
typedef pair<int, int> ii;
int main() {
	int N;
	scanf("%d", &N);
	int A[N + 1];
	A[0] = 0;
	for (int i = 1; i <= N; ++i) scanf("%d", &A[i]);
	int l = 1, u = N, m;
	while (l != u) {
		m = (l + u) / 2;
		stack<ii> st;
		bool can = true;
		for (int i = 1; i <= N; ++i) {
			if (A[i] > A[i - 1]) continue;
			else if (m == 1) {
				can = false;
				break;
			}
			while (!st.empty() && st.top().first > A[i]) st.pop();
			int lidx = A[i];
			while (!st.empty() && st.top().first == lidx && st.top().second == m - 1) st.pop(), --lidx;
			if (lidx == 0) {
				can = false;
				break;
			} else if (!st.empty() && st.top().first == lidx) {
				ii a = st.top();
				++a.second;
				st.pop();
				st.push(a);
			} else st.push(ii(lidx, 1));
		}
		if (can) u = m;
		else l = m + 1;
	}
	printf("%d", l);
	return 0;
}
