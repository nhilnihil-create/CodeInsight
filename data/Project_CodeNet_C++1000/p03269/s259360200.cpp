#include <bits/stdc++.h>

using namespace std;

int L;
vector < pair < pair < int, int >, int > > gr;

int main() {
	scanf("%d", &L);
	int lg = 0;
	while ((1 << (lg + 1)) <= L) lg++;
	for (int i = 1; i <= lg; i++) {
		gr.push_back({{i, i + 1}, (1 << (i - 1))});
		gr.push_back({{i, i + 1}, 0});
	}
	L -= (1 << lg);
	int cur = (1 << lg);
	for (int i = lg; i >= 1; i--) {
		if ((L >> (i - 1)) & 1) {
			gr.push_back({{i, lg + 1}, cur});
			cur += (1 << (i - 1));
		}
	}
	cout << lg + 1 << ' ' << (int)gr.size() << endl;
	for (int i = 0; i < (int)gr.size(); i++) {
		cout << gr[i].first.first << ' ' << gr[i].first.second << ' ' << gr[i].second << '\n';
	}
}