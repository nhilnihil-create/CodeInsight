#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <string>
#include <cmath>
#include <map>
#include <iomanip>
#include <tuple>
#include <functional>
#include <bitset>
#define INF 1000000009
#define LINF 1000000000000000009
#define EPS 1e-10
#define double long double
#define all(a) a.begin(),a.end()
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<ll, P> PP;
template<class T> bool chmax(T &a, const T&b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T&b) { if (a > b) { a = b; return 1; } return 0; }
ll gcd(ll n, ll m) { return (m ? gcd(m, n%m) : n); }
ll lcm(ll n, ll m) { return n / gcd(n, m)*m; }

int main(){
	string s;
	int k;
	cin >> s >> k;
	set<string> st;
	int n = s.size();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < min(k, n - i); j++) {
			string t = "";
			for (int k = 0; k <= j; k++) {
				t += s[i + k];
			}
			st.insert(t);
		}
	}
	for (int i = 0; i < k - 1; i++) {
		st.erase(*st.begin());
	}
	cout << *st.begin() << endl;
}