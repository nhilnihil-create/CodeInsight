#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
const int INF=1e9+7;

int main() {
	int N,C,rr=INF;
	cin >> N >> C;
	vector<vector<int>> D(C, vector<int>(C)), c(N, vector<int>(N)), sc;
	vector<map<int,int>> m(3, map<int,int>());

	rep(i,C)
		rep(j,C)
			cin >> D.at(i).at(j);
	rep(i,N)
		rep(j,N)
			cin >> c.at(i).at(j);

	rep(i,C-2)
		for(int j=i+1; j<C-1; ++j)
			for(int k=j+1; k<C; ++k) {
				vector<int> tc = {i, j, k};
				do {
					sc.push_back(tc);
				} while(next_permutation(tc.begin(), tc.end()));
			}

	rep(i,N)
		rep(j,N)
			if(m.at((i+j+2)%3).count(c.at(i).at(j)))
				++m.at((i+j+2)%3).at(c.at(i).at(j));
			else
				m.at((i+j+2)%3)[c.at(i).at(j)] = 1;

	rep(i,sc.size()) {
		int r = 0;
		rep(j,3)
			for(auto p : m.at(j))
				r += D.at(p.first-1).at(sc.at(i).at(j))*p.second;
		rr = min(rr, r);
	}

	cout << rr << endl;
}