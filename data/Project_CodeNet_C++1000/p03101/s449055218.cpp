#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<set>

using namespace std;

int main()
{
	int H, W;
	cin >> H >> W;
	int h, w;
	cin >> h >> w;

	cout << (H - h) * (W - w) << endl;
}
