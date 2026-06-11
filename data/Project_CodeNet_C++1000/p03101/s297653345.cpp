#include <bits/stdc++.h>
using namespace std;

int main() {
	int H,W,h,w;
	cin >> H >> W >> h >> w;
	int hi = H - h;
	int wi = W - w;
	cout << hi * wi << endl;
}
