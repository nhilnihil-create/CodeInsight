#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<functional>
#include<cmath>
#include<set>
#include<random>
#include<map>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
const long long mod = 1000000007;
typedef pair<int, int> P;
int a[114], b[114];


signed main() {
	int q; cin >> q;
	rep(x, q) {
		cin >> a[x] >> b[x];
		if (a[x] > b[x])swap(a[x], b[x]);

		if (a[x] == b[x]) {
			cout << a[x] * 2 - 2 << endl;
		}
		else if (abs(a[x] - b[x]) == 1) {
			cout << a[x] * 2 - 2 << endl;
		}
		else {
			int mn = sqrt(a[x] * b[x]);
			if (mn*mn == a[x] * b[x])mn--;
			if (mn*mn + mn >= a[x] * b[x])cout << mn * 2 - 2 << endl;
			else cout << mn * 2 - 1 << endl;
		}
	}
}