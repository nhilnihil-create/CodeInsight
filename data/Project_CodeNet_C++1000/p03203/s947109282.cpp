#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#define rep(i, n) for(i = 0; i < n; i++)
using namespace std;
typedef pair<int, int> P;

int h, w, n;
int py[200000], px[200000];
set<P> walls;
int tc[200000];	//tc[col] = col(>=0)列目に到達する最初の行(高橋君が壁にぶつかるのはアリとして考える）

int main() {
	int i;
	
	cin >> h >> w >> n;
	rep(i, n) {
		cin >> py[i] >> px[i];
		py[i]--;
		px[i]--;
		walls.insert(P(py[i], px[i]));
	}
	
	tc[0] = 0;
	for (i = 1; i < w; i++) {
		tc[i] = tc[i - 1] + 1;
		while (walls.find(P(tc[i], i)) != walls.end()) tc[i]++;
	}
	
	int ans = h;
	rep(i, n) {
		if (tc[px[i]] < py[i]) {
			ans = min(ans, py[i]);
		}
	}
	cout << ans << endl;
	
	return 0;
}