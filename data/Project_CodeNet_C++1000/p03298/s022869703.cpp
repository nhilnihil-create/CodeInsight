#include"bits/stdc++.h"
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
const long long mod = 1000000007;
const double pi = 3.1415926535897932;
const double eps = 0.000000000001;
const int inf = 1145141919;
struct edge { int to, cost; };
typedef pair<int, int>P;
typedef pair<int, P> PP;
typedef pair<string, string>PS;
map<PS,int>M1,M2;

signed main() {
	int n; cin >> n;
	string s; cin >> s;
	rep(i, 1<<n) {
		string t,u;
		rep(j, n) {
			if (i&(1 << j))t.push_back(s[j]);
			else u.push_back(s[j]);
		}
		M1[PS(t, u)]++;
	}
	string V;
	for (int i = n; i < 2 * n; i++)V.push_back(s[i]);
	reverse(V.begin(), V.end());
	rep(i, 1 << n) {
		string t, u;
		rep(j, n) {
			if (i&(1 << j))t.push_back(V[j]);
			else u.push_back(V[j]);
		}
		M2[PS(t, u)]++;
	}
	int sum = 0;

	for (auto itr = M1.begin(); itr != M1.end(); itr++) {
		PS A = itr->first;
		sum += itr->second*M2[A];
	}
	cout << sum << endl;
}