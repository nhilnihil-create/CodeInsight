#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep_lr(i,l,r) for(int i=(l);i<(r);i++)
#define all(x) (x).begin(),(x).end()
#define V vector
typedef V<int> vi;
typedef V<vi> vvi;
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
constexpr int INF = INT_MAX >> 1;
constexpr ll LINF = 5000000000000000LL;
constexpr int MOD = 1000000007;

int main() {

	int n;
	cin >> n;
	ll sum_jpy = 0, sum_bit = 0;

	rep(i, n) {
		string money, cur;
		cin >> money >> cur;
		if (cur == "JPY")sum_jpy += stol(money);
		else {
			ll bit = 0;
			rep(j, money.size()) {
				if (money[j] == '.')continue;
				bit *= 10;
				bit += money[j] - '0';
			}
			sum_bit += bit;
		}
	}

	cout << fixed << setprecision(6);
	cout << (sum_jpy * 100000000 + sum_bit * 380000) / 1e8 << endl;

}