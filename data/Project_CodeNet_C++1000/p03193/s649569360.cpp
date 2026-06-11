#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <math.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define INF 2 << 29
using Graph = vector<vector<int>>;

int main() {
	int n, h, w, a, b, ans = 0;
	cin >> n >> h >> w;
	rep(i, n) {
		cin >> a >> b;
		if (a >= h && b >= w)ans++;
	}
	cout << ans << endl;

}