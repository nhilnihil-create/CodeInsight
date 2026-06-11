#include<bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<tuple<int,int,int>> edges;
	--n;
	int now = 1;
	while (n) {
		if (n % 2 == 0) {
			edges.emplace_back(now,20,n);
			--n;
		}
		edges.emplace_back(now,now + 1,0);
		edges.emplace_back(now,now + 1,(n + 1) / 2);
		n >>= 1;
		++now;
	}
	while (now < 20) edges.emplace_back(now,now+1,0),++now;
	cout << now <<" " << (int)edges.size() <<"\n";
	for (auto&x : edges) {
		cout << get<0>(x) <<" " << get<1>(x) <<" " << get<2>(x) <<"\n";
	}
}