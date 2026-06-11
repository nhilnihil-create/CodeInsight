#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define dup(x,y) (((x)+(y)-1)/(y))
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pii;
const double EPS = 1e-10;
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1000000007;
const double PI = acos(-1);
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int main() {
	string s;
	cin >> s;
	int t1 = 0;
	rep(i,(int)s.size()) {
		if (i % 2 == 0 && s[i] == '0') t1++;
		if (i % 2 == 1 && s[i] == '1') t1++;
	}
	int t2 = 0;
	rep(i,(int)s.size()) {
		if (i % 2 == 1 && s[i] == '0') t2++;
		if (i % 2 == 0 && s[i] == '1') t2++;
	}
	cout << min(t1, t2) << endl;
}