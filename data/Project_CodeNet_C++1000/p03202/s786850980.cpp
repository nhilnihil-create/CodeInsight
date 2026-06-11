#include <iostream>
#include <vector>
#include <map>
#define rep(i, n) for(i = 0; i < n; i++)
using namespace std;

int n;
int a[200001];

bool check(int x) {
	map<int, int> str;	//(桁の位置(0-indexed), 桁の値(0～x-1)). (pos, 0)以外を記録.
	int i;
	
	for (i = 1; i < n; i++) {
		if (a[i] > a[i - 1]) continue;
		while (!str.empty() && str.rbegin()->first >= a[i]) str.erase(str.rbegin()->first);
		str[a[i] - 1]++;
		
		int cur = a[i] - 1;
		while (str[cur] >= x) {
			str[cur] = 0;
			cur--;
			str[cur]++;
			if (cur < 0) { return false; }
		}
	}
	return true;
}

int main() {
	int i;
	
	cin >> n;
	a[0] = 0;
	rep(i, n) cin >> a[i + 1];
	n++;
	
	//check(1)を呼び出すと,桁上がりの処理がO(A_i)回行われる可能性があるので、答え=1かの判定は先にやる
	bool ok1 = true;
	for (i = 1; i < n; i++) if (a[i] <= a[i - 1]) ok1 = false;
	if (ok1) { cout << 1 << endl; return 0; }
	
	//2分探索
	int st = 1, ed = n, mid;	//xxxooo, (st, ed]
	while (ed - st >= 2) {
		mid = (st + ed) / 2;
		if (check(mid)) ed = mid;
		else st = mid;
	}
	cout << ed << endl;
	return 0;
}