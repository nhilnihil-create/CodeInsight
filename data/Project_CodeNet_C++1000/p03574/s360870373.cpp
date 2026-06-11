#include<iostream>
#include<string.h>
#include<vector>
#define rep(i,n) for(int i=0;i<(int)n;i++)
using namespace std;
int h, w;
int hw(vector<vector<char>> &a,int x,int y) {
	if (a.at(y).at(x) == '#') return 0;
	int dx[] = { -1,0,1 }, dy[] = { -1,0,1 };
	int count = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (x + dx[j] >= 0 && x + dx[j] < w && y + dy[i] < h && y + dy[i] >= 0) {
				if (a.at(y + dy[i]).at(x + dx[j]) == '#')count++;
			}
		}

	}
	char c = count + '0';
	a.at(y).at(x) = c;
	return 0;
}
int main() {
	cin >> h >> w;
	vector<vector<char>> s(h,vector<char>(w));
	for (int i = 0; i < h; i++) {
		rep(j, w) {
			cin >> s.at(i).at(j);
		}
	}
	rep(i, h) {
		rep(j, w) {
			hw(s, j, i);
		}
	}
	rep(i, h) {
		rep(j, w) {
			cout << s.at(i).at(j);
		}
		cout << endl;
	}
	
}
