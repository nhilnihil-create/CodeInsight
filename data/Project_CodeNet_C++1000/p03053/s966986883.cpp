#include<iostream>
#include<string>
#include<vector>
#include<numeric>
#include<math.h>
#include<algorithm>
#include<iomanip>
#include<bitset>
#include<list>
using namespace std;

struct Info {
	int r;
	int c;
	int cnt;
	Info(int dr, int dc, int dcnt) {
		r = dr;
		c = dc;
		cnt = dcnt;
	}
};

int main() {

	int H, W;
	cin >> H >> W;

	vector<string> A(H, "");
	int pos = 0;
	list<Info> loc;
	for (int i = 0; i < H; i++) {
		cin >> A[i];
		pos = A[i].find('#', 0);
		while (pos != string::npos) {
			loc.push_back(Info(i, pos, 0));
			pos = A[i].find('#', pos + 1);
		}
	}

	vector<Info> nns = { Info(-1,0,1), Info(1,0,1) , Info(0,-1,1) , Info(0,1,1) };

	Info val = Info(0,0,0); 
	Info dval = Info(0, 0, 0);

	while (loc.size() != 0) {
		val = loc.front();
		loc.pop_front();
		for (int i = 0; i < nns.size(); i++) {
			dval = val;
			dval.r += nns[i].r;
			dval.c += nns[i].c;
			if (0 <= dval.r && dval.r < H && 0 <= dval.c && dval.c < W) {
				if (A[dval.r][dval.c] == '.') {
					A[dval.r][dval.c] = '#';
					loc.push_back(Info(dval.r, dval.c, dval.cnt + nns[i].cnt));
				}
			}
		}
	}
	
	cout << val.cnt << endl;

	return 0;
}
