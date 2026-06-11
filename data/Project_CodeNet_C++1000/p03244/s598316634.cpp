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
	int n;
	cin >> n;
	vector<P> odd;
	vector<P>even;

	rep(i, n) {
		int input;
		cin >> input;
		bool flag = true;
		if (i % 2 == 0) {
			rep(j, even.size()) {
				if (even[j].first == input) {
					flag = false;
					even[j].second++;
				}
			}
			if (flag) {
				even.pb(P(input, 1));
			}
		}
		else {
			rep(j, odd.size()) {
				if (odd[j].first == input) {
					flag = false;
					odd[j].second++;
				}
			}
			if (flag) {
				odd.pb(P(input, 1));
			}
		}
	}
	sort(even.begin(), even.end(), pairCompare);
	sort(odd.begin(), odd.end(), pairCompare);

	if (even[0].first == odd[0].first) {
		if (even.size() == 1 && odd.size() == 1) {
			print(n / 2);
		}
		else {
			int sub = max((even[0].second + odd[1].second), (odd[0].second + even[1].second));
			print(n - sub);
		}
	}
	else {
		print(n - odd[0].second - even[0].second);
	}
}