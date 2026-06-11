#include<iostream>
#include<string>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
#include<functional>
#include<iomanip>
#include<queue>
#include<cassert>
#include<tuple>
#include<set>
#include<map>
#include<list>
#include<bitset>

#define PB push_back
#define ALL(a)  (a).begin(),(a).end()
#define DWN(a)  (a).begin(),(a).end(), greater<int>()
#define rep(i, m) for (int i = 0; i < m; i++)
#define REP(i, n, m) for (int i = n; i < m; i++)

#define mod 1000000007

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };
const int INF = (int)1e9;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);

	int minI = 1, maxI = 1;
	for(int i = 1; i < n; i++) {
		cin >> a[i];
		minI = (a[i] < a[minI]) ? i : minI;
		maxI = (a[i] > a[maxI]) ? i : maxI;
	}
	int piv = minI;
	if (a[minI] + a[maxI] > 0) {
		piv = maxI;
	}

	cout << 2 * n - 1 << endl;
	for(int i = 1; i <= n; i++) {
		cout << piv << " " << i << endl;
	}
	if (a[piv] > 0) {
		for(int i = 1; i <= n - 1; i++) {
			cout << i << " " << i + 1 << endl;
		}
	}
	else {
		for(int i = n; i >= 2; i--) {
			cout << i << " " << i - 1 << endl;
		}
	}
	return 0;
}