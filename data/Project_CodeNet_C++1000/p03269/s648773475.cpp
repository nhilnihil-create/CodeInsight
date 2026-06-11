#include <bits/stdc++.h>
#define eb emplace_back
#define sz(V) ((int)(V).size())
using namespace std;
typedef pair<int, int> pii;

struct EDG {
	EDG(int a, int b, int c)
		: a(a), b(b), c(c) {}
	int a, b, c;
	void prt() { printf("%d %d %d\n", a, b, c); }
};

vector<EDG> EV;

int N;

int main() {
	cin >> N;

	for(int i = 1; i < 19; i++) {
		EV.eb(i, i+1, 0);
		EV.eb(i, i+1, 1<<(i-1));
	}
	for(int i = 19; i; i--) {
		for(int c = 1<<(i-1); c <= N;) {
			EV.eb(i, 20, N-c);
			N -= c;
		}
	}

	printf("20 %d\n", sz(EV));
	for(auto &v : EV) v.prt();
	return 0;
}