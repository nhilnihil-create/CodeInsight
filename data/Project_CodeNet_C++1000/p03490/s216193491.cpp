#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <numeric>
#include <regex>
#include <tuple>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
#define MOD 1000000007 // 10^9 + 7
#define INF 1000000000 // 10^9
#define LLINF 1LL<<60

bool dpx[8009][16009];
bool dpy[8009][16009]; // dp[i][k] : i回目の移動後にk-8000にいるかどうか



int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	string S; cin >> S;
	int x, y; cin >> x >> y;


	vector<int> xpath, ypath;
	bool way = true; // 1 : x軸方向
					 // 0 : y軸方向
	int lpath = 0;

	for (int i = 0; i < S.size(); i++) {
		if (S[i] == 'F') lpath++;
		else { // S[i] == 'T'
			if (way) xpath.push_back(lpath);
			else ypath.push_back(lpath);
			lpath = 0;
			
			way = !way; // 回転
		}
	}
	if (way) xpath.push_back(lpath);
	else ypath.push_back(lpath);
	lpath = 0;
	
	

	/*
	// 確認
	cout << "x  : ";
	for (int i = 0; i < xpath.size(); i++) cout << xpath[i] << " ";
	cout << endl;
	cout << "y  : ";
	for (int i = 0; i < ypath.size(); i++) cout << ypath[i] << " ";
	cout << endl;
	*/


	
	// x,yを構成できるか
	dpx[0][8000] = dpy[0][8000] = true;

	dpx[1][8000 + xpath[0]] = true;
	for (int i = 2; i <= xpath.size(); i++) {
		int d = xpath[i - 1];
		for (int j = 0; j <= 16000; j++) {
			if (dpx[i - 1][j]) {
				dpx[i][j - d] = true;
				dpx[i][j + d] = true;
			}
		}
	}

	for (int i = 1; i <= ypath.size(); i++) {
		int d = ypath[i - 1];
		for (int j = 0; j <= 16000; j++) {
			if (dpy[i - 1][j]) {
				dpy[i][j - d] = true;
				dpy[i][j + d] = true;
			}
		}
	}

	if (dpx[xpath.size()][x + 8000] && dpy[ypath.size()][y + 8000]) cout << "Yes" << endl;
	else cout << "No" << endl;

	return 0;
}