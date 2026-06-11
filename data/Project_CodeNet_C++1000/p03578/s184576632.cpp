#include <cstdio>
#include <set>
using namespace std;

int main() {
	multiset<int> ms;
	int n, m, t;
	bool flag = 0;
	scanf("%d", &n);
	while (n--) {
		scanf("%d", &t);
		ms.insert(t);
	}
	scanf("%d", &m);
	while (m--) {
		scanf("%d", &t);
		if (!ms.count(t))
			flag = 1;
		else ms.erase(ms.find(t));
	}
	puts(flag ? "NO" : "YES");
	return 0;
}
