#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
	int H, W, h, w;
	cin >> H >> W >> h >> w;
	int white = H * W;
	white -= H * w + (h * (W - w));
	cout << white << endl;
	return 0;
}