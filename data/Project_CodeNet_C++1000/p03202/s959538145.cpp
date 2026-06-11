#include <cstdio>
#include <vector>
using namespace std;

typedef long long ll;
const int N = 1 << 18;
vector <pair <int, int> > s;
int a[N];
int n;

void dbg() {
	for (int j = 0; j < (int) s.size(); ++ j)
		printf("(%d, %d) ", s[j].first, s[j].second);
	puts("");
}

bool plus(int lim) {
	int i;
	for (i = (int) s.size() - 1; ~i && s[i].first == lim; -- i);
	if (!~i) return 0;
	if (!s[i].second) return 0;
	s[i].second --;
	int nw = s[i].first;
	if (!s[i].second) {
		for (int j = i; j < (int) s.size() - 1; ++ j) s[j] = s[j + 1];
		s.pop_back();
	}
	else ++ i;
	s.push_back({0, 0});
	for (int j = (int) s.size() - 1; j > i; -- j) s[j] = s[j - 1];
	s[i] = {nw + 1, 1};
	int x = 0;
	for (int j = (int) s.size() - 1; j > i; -- j) {
		x += s.back().second;
		s.pop_back();
	}
	if (x) s.push_back(make_pair(1, x));
	return 1;
}

bool chk(int lim) {
	s.clear();
	int len = 0;
	for (int i = 0; i < n; ++ i) {
		if (len > a[i]) {
			for (int j = (int) s.size() - 1; len > a[i]; -- j) {
				if (len - s[j].second < a[i]) {
					s[j].second -= len - a[i];
					len = a[i];
					break;
				}
				len -= s[j].second;
				s.pop_back();
			}
			if (!plus(lim)) return 0;
		}
		else if (len < a[i]) { s.push_back({1, a[i] - len}); len = a[i]; }
		else if (!plus(lim)) return 0;
//		dbg();
	}
	return 1;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++ i) scanf("%d", &a[i]);
	int lb = 1, rb = 1 << 30;
	while (lb < rb) {
		int md = (lb + rb) >> 1;
		if (chk(md)) rb = md;
		else lb = md + 1;
	}
	printf("%d\n", lb);
	return 0;
}