#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <queue>
#include <iomanip>

using namespace std;
typedef long long ll;

int main() {
	int H, W, N;
	int sr, sc;
	cin >> H >> W >> N;
	cin >> sr >> sc;
	getchar();
	string s, t;
	getline(cin, s);
	getline(cin, t);
	int position = sc;
	for (int i = 0; i < N; i++) {
		if (s[i] == 'R') position++;
		if (position > W) { cout << "NO" << endl; return 0; }
		if (t[i] == 'L' && position > 1) position--;
	}
	position = sc;
	for (int i = 0; i < N; i++) {
		if (s[i] == 'L') position--;
		if (position < 1) { cout << "NO" << endl; return 0; }
		if (t[i] == 'R' && position <W) position++;
	}
	position = sr;
	for (int i = 0; i < N; i++) {
		if (s[i] == 'U') position--;
		if (position < 1) { cout << "NO" << endl; return 0; }
		if (t[i] == 'D' && position<H) position++;
	}
	position = sr;
	for (int i = 0; i < N; i++) {
		if (s[i] == 'D') position++;
		if (position > H) { cout << "NO" << endl; return 0; }
		if (t[i] == 'U'&& position > 1) position--;
	}
	cout << "YES" << endl;
	return 0;
}