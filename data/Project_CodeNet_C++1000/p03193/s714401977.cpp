#include <iostream>
#include<algorithm>
#include<sstream>
#include<cmath>
#include<vector>
#include<iomanip>
#include<map>
#include<set>
#include<queue>
#include<deque>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(int i = 0; i < n;i++)
int main() {
	int n, h, w,sum =0;cin >> n >> h >> w;
	vector<int> a(n), b(n);
	rep(i, n) {
		cin >> a[i] >> b[i];
		if (a[i] >= h && b[i] >= w) sum++;
	}
	cout << sum << endl;
}