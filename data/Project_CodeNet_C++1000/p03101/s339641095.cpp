#include<iostream>
#include<string>
#include<vector>
#include<numeric>
#include<math.h>
#include<algorithm>
#include<iomanip>
using namespace std;

int main() {

	long H, W;
	cin >> H >> W;

	long h, w;
	cin >> h >> w;

	long ans = h * w + (W - w) * h + (H - h) * w;
	ans = H * W - ans;
	cout << ans << endl;

	return 0;
}
