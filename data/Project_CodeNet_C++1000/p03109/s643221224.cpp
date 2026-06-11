#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i, s, n) for (int i = (s); i < (n); ++i)
#define rrep(i, n, g) for (int i = (n)-1; i >= (g); --i)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define len(x) (int)(x).size()
#define dup(x, y) (((x) + (y)-1) / (y))
#define pb push_back
#define Field(T) vector<vector<T>>
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  string s;
	cin >> s;
	if (s[5] == '0'){
		if (s[6] == '1' || s[6] == '2' || s[6] == '3' || s[6] == '4'){
			cout << "Heisei" << endl;
		}
		else cout << "TBD" << endl;
	}
	else cout << "TBD" << endl;
}