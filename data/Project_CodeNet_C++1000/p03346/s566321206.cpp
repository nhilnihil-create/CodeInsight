#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef pair<int, int> P;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define all(x) (x).begin(),(x).end()
vi dy = { 0,0,1,-1 };
vi dx = { 1,-1,0,0 };
constexpr auto INF = 1050000000;
constexpr auto MOD = 1000000007;


int main() {
	int n;
	cin >> n;
	set<int> l;

	rep(i, n) {
		int p;
		cin >> p;
		l.insert(p);
		if (*l.lower_bound(p-1)==p-1)l.erase(p - 1);
	}

	int mxl = *l.lower_bound(0);
	int ss = l.size() - 1;

	rep(i,ss) {
		int x, y;

		x = *l.lower_bound(0);
		y = *l.upper_bound(x);

		mxl = max(mxl,y-x);
		l.erase(x);
	}

	cout << n - mxl << endl;
}