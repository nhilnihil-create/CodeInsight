#include <bits/stdc++.h>
using namespace std;

#define li long long int
#define rep(i, to) for (li i = 0; i < ((li)(to)); i++)
#define repp(i, start, to) for (li i = ((li)(start)); i < ((li)(to)); i++)
typedef pair<li, li> PI;


li num_v = 1;

int main(void)
{
	li l;
	cin >> l;
	li beki = 1;
	while (beki <= l) {
		beki *= 2;
		num_v++;
	}
	beki /= 2;
	num_v--;
	li diff = l - beki;

	vector<vector<PI>> edge(num_v);
	li now_rest = beki;
	repp(i, 1, num_v) {
		edge[i].push_back({i - 1, 0});
		edge[i].push_back({i - 1, 1ll << (i - 1)});
		if ((diff & (1ll << (i - 1))) > 0) {
			edge[num_v - 1].push_back({i - 1, now_rest});
			now_rest += (1ll << (i - 1));
		}
	}
	li num_e = 0;
	rep(i, num_v) {
		num_e += edge[i].size();
	}
	cout << num_v << " " << num_e << endl;

	rep(i, num_v) {
		for (auto& item : edge[i]) {
			cout << num_v - i << " " << num_v - item.first << " " << item.second << endl;
		}
	}
	return 0;
}