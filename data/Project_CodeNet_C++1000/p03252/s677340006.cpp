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

typedef pair<int, int> P;

bool pairCompare(const P& firstElof, const P& secondElof)
{
	return firstElof.second > secondElof.second;
}

signed main(void)
{
	string s, t;
	cin >> s >> t;
	int n = s.size();
	vector<int>start(26,-1), goal(26,-1);
	rep(i, n) {
		int si = s[i] - 'a';
		int ti = t[i] - 'a';

		if (start[si] != -1 || goal[ti] != -1) {
			if (start[si] != ti || goal[ti] != si) {
				print("No");
				return 0;
			}
		}
		else {
			start[si] = ti;
			goal[ti] = si;
		}
	}
	print("Yes");

	
}