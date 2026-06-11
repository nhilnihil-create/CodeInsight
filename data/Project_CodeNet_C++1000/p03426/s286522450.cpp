#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
typedef pair<int,int> P;

int main() {
	int H,W,D,A,Q,L,R;
	cin >> H >> W >> D;
	vector<vector<int>> m(H, vector<int>(W,0));
	vector<P> p(H*W);

	rep(i,H)
		rep(j,W) {
			cin >> A;
			p.at(A-1) = P(i,j);
		}

	rep(i,D) {
		int x=i+D;
		while(x < H*W) {
			int sy=p.at(x-D).first, sx=p.at(x-D).second, ty=p.at(x).first, tx=p.at(x).second;
			m.at(ty).at(tx) = m.at(sy).at(sx) + abs(sy-ty) + abs(sx-tx);
			x += D;
		}
	}

	cin >> Q;
	rep(i,Q) {
		cin >> L >> R;
		--L, --R;
		cout << m.at(p.at(R).first).at(p.at(R).second) - m.at(p.at(L).first).at(p.at(L).second) << endl;
	}
}