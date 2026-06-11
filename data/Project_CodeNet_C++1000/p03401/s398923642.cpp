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
	vector<int>a(n);

	rep(i, n) {
		cin >> a[i];
	}

	vector<int>b(n + 1);//b[i]=i-1→iのコスト
	int sum = abs(a[0]);
	b[0] = abs(a[0]);
	rep1(i, n) {
		b[i] = abs(a[i-1] - a[i]);
		sum += b[i];
	}
	b[n] = abs(a[n - 1]);
	sum += b[n];
	int ans;
	//println(sum);
	rep(i, n) {
		if (i == 0) {
			ans = sum - b[0]-b[1] +abs(a[1]);
		}
		else if (i == n - 1) {
			ans = sum - b[n]-b[n-1] + abs(a[n-2]);
		}
		else {
			ans = sum - b[i] - b[i + 1] + abs(a[i - 1] - a[i+1]);
		}
		cout << ans << endl;
	}
}