#include<bits/stdc++.h>
using namespace std;

int main() {
	int h, w; cin >> h >> w;
	int a[h][w];
	vector<int> y, x, yd, xd;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if(j != w - 1) {
				if(a[i][j] % 2 == 1) {
					a[i][j]--;
					a[i][j+1]++;
					y.push_back(i+1), x.push_back(j+1);
					yd.push_back(i+1), xd.push_back(j+2);
				}
			}
			else {
				if(i != h - 1) {
					if(a[i][j] % 2 == 1) {
						a[i][j]--;
						a[i+1][j]++;
						y.push_back(i+1), x.push_back(j+1);
						yd.push_back(i+2), xd.push_back(j+1);
					}
				}
			}
		}
	}

	cout << y.size() << endl;
	for (int i = 0; i < y.size(); i++)
	{
		cout << y[i] << " " << x[i] << " ";
		cout << yd[i] << " " << xd[i] << endl;
	}

	return 0;
}
