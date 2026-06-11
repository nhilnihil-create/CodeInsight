//「1文字指定される→辺を移動する」を交互に繰り返すゲームと同値。
//その場合、Aとしか繋がってない頂点、Bとしか繋がってない頂点、何とも繋がってない頂点に行くと、次のターンにゲームオーバーなので、
//A,B両方と繋がっている頂点以外は削除しても解に影響しないことが分かる。そのような操作を繰り返していき、頂点が残らなければ
//No. 頂点が残った場合は、「どの頂点もA,B両方と繋がっている」ので、何処にいても必ず移動できる。よってYes.
#include <iostream>
#include <string>
#include <queue>
#define rep(i, n) for(i = 0; i < n; i++)
using namespace std;

int n, m;
string s;
vector<int> et[200000];
int da[200000], db[200000];
bool erased[200000];

int main() {
	int i, j;
	
	cin >> n >> m >> s;
	rep(i, m) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		et[a].push_back(b);
		et[b].push_back(a);
	}
	
	rep(i, n) {
		rep(j, et[i].size()) {
			int v = et[i][j];
			if (s[v] == 'A') da[i]++;
			else db[i]++;
		}
	}
	
	queue<int> que;
	rep(i, n) if (da[i] == 0 || db[i] == 0) { erased[i] = true; que.push(i); }
	while (!que.empty()) {
		int v = que.front(); que.pop();
		rep(i, et[v].size()) {
			int nv = et[v][i];
			if (s[v] == 'A') { da[nv]--; }
			if (s[v] == 'B') { db[nv]--; }
			if ((da[nv] == 0 || db[nv] == 0) && !erased[nv]) {
				erased[nv] = true;
				que.push(nv);
			}
		}
	}
	
	rep(i, n) {
		if (!erased[i]) { cout << "Yes" << endl; return 0; }
	}
	cout << "No" << endl;
	return 0;
}