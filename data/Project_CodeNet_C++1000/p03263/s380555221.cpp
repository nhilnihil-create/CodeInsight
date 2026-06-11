#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int h, w;
	cin >> h >> w;
	vector<vector<int>>a(h, vector<int>(w));
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> a.at(i).at(j);
			a.at(i).at(j) %= 2;
		}
	}
	vector<vector<int>>yxyx(0, vector<int>(4));
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w - 1; j++) {
			if (a.at(i).at(j) == 1) {
				yxyx.push_back({ i,j,i,j + 1 });
				a.at(i).at(j)--;
				a.at(i).at(j + 1)++;
			}
			else a.at(i).at(j) %= 2;
		}
	}
	for (int i = 0; i < h-1; i++) {
		a.at(i).at(w - 1) %= 2;
		if (a.at(i).at(w - 1) == 1) {
			yxyx.push_back({ i,w - 1,i + 1,w - 1 });
			a.at(i).at(w - 1)--;
			a.at(i + 1).at(w - 1)++;
		}
	}
	a.at(h - 1).at(w - 1) %= 2;
	cout << yxyx.size() << endl;
	for (int i = 0; i < yxyx.size(); i++)cout << yxyx.at(i).at(0)+1 << " " << yxyx.at(i).at(1) + 1 << " " << yxyx.at(i).at(2) + 1 << " " << yxyx.at(i).at(3) + 1 << endl;

}