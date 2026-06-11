#include <iostream>
using namespace std;

int main() {
	int h, w, hs, ws;
	cin >> h >> w >> hs >> ws;
	int ans = h * w;
	ans -= h * ws;
	ans -= (w - ws) * hs;
	cout << ans << endl;
	return 0;
}