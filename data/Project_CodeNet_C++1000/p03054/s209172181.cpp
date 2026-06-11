#include<iostream>
#include<string>
#include<algorithm>
 
using namespace std;
 
int main() {
	int H, W, N;
	string S, T;
	int x, y;
	cin >> H >> W >> N >> y >> x >> S >> T;
	x--, y--;
 
	int l = 0, r = W;//[l, r)の区間で存在したらセーフ
	if (S[N - 1] == 'L') {
		l++;
	}
	if (S[N - 1] == 'R') {
		r--;
	}
	for (int i = N - 2; i >= 0; i--) {
		if (T[i] == 'R') {
			l = max(0, l - 1);
		}
		if (T[i] == 'L') {
			r = min(W, r + 1);
		}
		if (S[i] == 'L') {
			l++;
		}
		if (S[i] == 'R') {
			r--;
		}
		if (r <= l) {
			cout << "NO" << endl;
			return 0;
		}
	}
	if (!(l <= x && x < r)) {
		cout << "NO" << endl;
		return 0;
	}
 
	int d = 0, u = H;//[d, u)の区間で存在したらセーフ
	if (S[N - 1] == 'D'){
		u--;
	}
	if (S[N - 1] == 'U') {
		d++;
	}
	for (int i = N - 2; i >= 0; i--) {
		if (T[i] == 'U') {
			u = min(H, u + 1);
		}
		if (T[i] == 'D') {
			d = max(0, d - 1);
		}
		if (S[i] == 'D') {
			u--;
		}
		if (S[i] == 'U') {
			d++;
		}
		if (u <= d) {
			cout << "NO" << endl;
			return 0;
		}
	}
	if (!(d <= y && y < u)) {
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	return 0;
}