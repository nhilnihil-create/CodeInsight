#include <stdio.h>
#include <vector>
#include <tuple>

using namespace std;

typedef tuple<int, int, int> ti;

int l;

int main() {
	scanf("%d", &l);
	int n = 1;
	while ((1 << n) <= l) n++;
	vector<ti> res;
	int w = (1 << (n - 2));
	for (int i = 2; i <= n; i++) {
		res.push_back(ti(i - 1, i, 0));
		res.push_back(ti(i - 1, i, w));
		w >>= 1;
	}
	int add = (1 << (n - 1));
	while (add < l) {
		for (int i = 2; i <= n; i++) {
			if (add + (1 << (n - i)) <= l) {
				res.push_back(ti(1, i, add));
				add += (1 << (n - i));
				break;
			}
		}
	}
	printf("%d %d\n", n, (int)res.size());
	for (int i = 0; i < res.size(); i++)
		printf("%d %d %d\n", get<0>(res[i]), get<1>(res[i]), get<2>(res[i]));
	return 0;
}