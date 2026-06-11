#include <bits/stdc++.h>


using namespace std;
typedef long long ll;
#define REP(i,n) for(int i=0; i<int(n); i++)
#define FOR(i,m,n) for(int i=int(m); i<int(n); i++)
#define ALL(obj) (obj).begin(),(obj).end()
#define VI vector<int>
#define VLL vector<long long>
#define VVI vector<vector<int>>
#define VVLL vector<vector<long long>>
#define VC vector<char>
#define VS vector<string>
#define VVC vector<vector<char>>
#define fore(i,a) for(auto &i:a)

typedef pair <int, int> P;
template<class T> bool chmax(T &a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, T b) { if (a > b) { a = b; return true; } return false; }
const int  INF = 1 << 30;
const ll INFL = 1LL<<60;
const ll mod = 1000000007;		




int main() {

	int l;
	cin >> l;
	int a = l;
	int n = 0;
	while (a) {
		n++;
		a /= 2;
	}


	n--;

	int c = 0;
	vector<pair<int, pair<int, int>>> v;

	REP(i, n) {
		c += pow(2, i);
		v.push_back({ i + 1,{i + 2,0} });
		v.push_back({ i + 1,{i + 2,pow(2,i)} });
	}

	
	if (2 * c + 2 == l) {
		cout << n + 2 << ' ';
		cout << v.size() + 2 << endl;
		REP(i, v.size()) {
			cout << v[i].first << ' ' << v[i].second.first << ' ' << v[i].second.second << endl;
		}
		cout << n + 1 << ' ' << n + 2 << ' ' << 0 << endl;
		cout << n + 1 << ' ' << n + 2 << ' ' << c + 1 << endl;
		return 0;
	}

	cout << n + 1 << ' ';

	int d = c;
	d++;

	while (d != l) {
		for (int i = n; i >= 0; i--) {
			if (pow(2, i) - 1 + d < l) {
				v.push_back({ i + 1,{n + 1,d} });
				d += pow(2, i);
				break;
			}
		}
	}

	cout << v.size() << endl;

	REP(i, v.size()) {
		cout << v[i].first << ' ' << v[i].second.first << ' ' << v[i].second.second << endl;
	}
}

