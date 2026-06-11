#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < (n); i++)
#define all(a) (a).begin(),(a).end()
#define SORT(a) sort(all(a))
#define rSORT(a, i) sort(all(a),(i))

using ll = long long;
constexpr ll INF = 10000000000;
constexpr ll MOD = 1000000007;
const int MAX_N = 110000; 
constexpr double EPS = 1E-11;

using namespace std;

//fixed << setprecision(10)

int main() {
	int n; 
	cin >> n;

	vector<double>a(n);
	double sum = 0;
	rep(i, n) {
		cin >> a[i];
		sum += a[i];
	}

	double avr = (double)sum / n;

	vector<pair<double, int> >ans;

	for (int i = 0; i < n; i++) {
		ans.push_back(make_pair(abs(a[i] - avr), i));
	}
	sort(all(ans));
	cout << ans[0].second << endl;
}