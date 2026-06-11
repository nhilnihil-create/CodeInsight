#include<bits/stdc++.h>
#define fi first
#define se second
#define rep(i, n) for(int (i) = 0; (i) < (n); (i)++)
#define rrep(i, n) for (int (i) = 1; (i) <= (n); (i++))
#define rng(a) a.begin(),a.end()
#define rrng(a) a.rbegin(),a.rend()
#define pb push_back
#define eb emplace_back
#define yn {puts("Yes");}else {puts("No");}
#define printd(x) printf("%.12f\n", x);
template<class T> bool chmin(T& a, const T& b) {if (a > b) {a = b; return 1;} return 0;}
template<class T> bool chmax(T& a, const T& b) {if (a < b) {a = b; return 1;} return 0;}
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main() {
	int h, w, n, sr, sc;
	cin >> h >> w >> n >> sr >> sc;
	string s, t;
	cin >> s >> t;

	
	int curX = sc;
	rep (i, n) {
		if (s[i] == 'R') curX++;
		if (curX > w) {
			cout << "NO" << endl;
			return 0;
		}
		if (t[i] == 'L') if (curX != 1) curX--;
	}
	curX = sc;
	rep (i, n) {
		if (s[i] == 'L') curX--;
		if (curX < 1) {
			cout << "NO" << endl;
			return 0;
		}
		if (t[i] == 'R') if (curX != w) curX++;
	}
	int curY = sr;
	rep (i, n) {
		if (s[i] == 'U') curY--;
		if (curY < 1) {
			cout << "NO" << endl;
			return 0;
		}
		if (t[i] == 'D') if (curY != h) curY++;
	}
	curY = sr;
	rep (i, n) {
		if (s[i] == 'D') curY++;
		if (curY > h) {
			cout << "NO" << endl;
			return 0;
		}
		if (t[i] == 'U') if (curY != 1) curY--;
	}

	cout << "YES" << endl;
	return 0;
}