
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<bitset>
typedef long long ll;
using namespace std;
#define INF (1 << 30)
#define INFLL (1LL << 60)
#define rep(i, n) for(int i=0; i<(n); ++i)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int main()
{
	int N; cin >> N;
	int ans = 0, bf = 0;
	rep(i, N) {
		int h; cin >> h;
		if (h >= bf) ans = ans + h - bf;
		bf = h;
	}
	cout << ans << endl;
	return 0;
}
