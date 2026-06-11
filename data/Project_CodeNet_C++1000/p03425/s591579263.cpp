#include "bits/stdc++.h"
#include <set>

using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define RFOR(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep1(i, n) for (int i = 1; i < (n); i++)
#define rrep(i, n) for (int i = (n)-1; i >= 0; i--)
#define all(i) (i).begin(), (i).end()
#define rall(i) (i).begin(), (i).end(), greater<int>()
#define int long long
#define elif else if
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define fst first
#define sec second
#define mod 1000000007
#define INF 10e10
template <typename T>

void print(T x)
{
	std::cout << x << " ";
}

template <typename T>

void println(T x)
{
	std::cout << x << "\n";
}


signed main(void) {
	int n;
	cin >> n;
	vector<int>name(5);
	string march = "MARCH";
	rep(i, n) {
		string s;
		cin >> s;
		rep(i, 5) {
			if (s[0] == march[i]) name[i]++;
		}
	}
	int ans = 0;
	for (int bit = 0; bit < (1 << 5); ++bit) {
		vector<int> a;
		for (int i = 0; i < 5; ++i) {
			if (bit & (1 << i)) {
				a.push_back(i);
			}
		}
		if (a.size() != 3)continue;
		ans += name[a[0]] * name[a[1]] * name[a[2]];
	}
    cout<<ans<<endl;
}
