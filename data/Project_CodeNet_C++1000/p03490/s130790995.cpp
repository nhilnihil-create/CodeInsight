#include <iostream>
#include <vector>
#include <deque>

using namespace std;

const int MAX = 8009 * 2, ORIGIN = 8009;
int b[MAX][MAX], x, y;
vector<int> sy, sx, d;

bool valid(int p);
deque<vector<int>> dp(const vector<int> &iv, const vector<int> &sv);

bool valid(int p) {
	return (0 <= p && p < MAX);
}

void printv(const vector<int> &v) {
	for (int i = ORIGIN - 10; i < ORIGIN + 10; i++) {
		cerr << v[i] << ' ';
	}
	cout << '\n';
}

void debug(const vector<int> &v) {
	for (auto ch : v) {
		cout << ch << ' ';
	}
	cout << '\n';
}

deque<vector<int>> dp(const vector<int> &iv, const vector<int> &sv) {
	deque<vector<int>> l;
	l.push_back(iv);
	for (int i = 0; i < sv.size(); i++) {
		vector<int> newv(MAX);
		for (int j = 0; j < MAX; j++) {
			 if (valid(j - sv[i]) && l.front()[j - sv[i]] == 1) {
			 	newv[j] = 1;
			 } else if (valid(j + sv[i]) && l.front()[j + sv[i]] == 1) {
			 	newv[j] = 1;
			 }
		}
		l.push_back(newv);
//		printv(newv);
		l.pop_front();
	}
	return l;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	string s;
	cin >> s >> x >> y;
	int dist = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'T') break;
		dist++;
	}
	int dir = -1, start = dist;
	dist = 0;
	for (int i = start + 1; i < s.size(); i++) {
		if (s[i] == 'F') dist++;
		else {
			if (dist != 0) d.push_back(dir * dist);
			dir *= -1;
			dist = 0;
		}
	}
	if (dist != 0) d.push_back(dir * dist);
	for (int i = 0; i < d.size(); i++) {
		if (d[i] < 0) sy.push_back(abs(d[i]));
		else sx.push_back(abs(d[i]));
	}
//	debug(sx);
//	debug(sy);
	vector<int> ix(MAX), iy(MAX);
	ix[ORIGIN + start] = iy[ORIGIN] = 1;
	vector<int> dy = dp(iy, sy).front(), dx = dp(ix, sx).front();
	if (dy[ORIGIN + y] && dx[ORIGIN + x]) {
		cout << "Yes\n";
	} else {
		cout << "No\n";
	}
	
	return 0;
}
