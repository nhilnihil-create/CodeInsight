#include <iostream> 
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<iomanip>
#include<sstream>
#include<cmath>
#include<bitset>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define req(i,n) for(int i = 1;i <=  n; i++)
#define rrep(i,n) for(int i = n -1;i >= 0;i--)
typedef long long int ll;
typedef long double ld;
const ll INF = (1 << 31) - 1;
template<typename A, size_t N, typename T>
void Fill(A(&array)[N], const T & val) {
    std::fill((T*)array, (T*)(array + N), val);
}
const int MAX = 510000;
const ll MOD = 1000000007;
int ans = -INF, n, p[100][11];
bool f[100][10];
int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) for (int j = 0; j < 10; ++j) cin >> f[i][j];
	for (int i = 0; i < n; ++i) for (int j = 0; j <= 10; ++j) cin >> p[i][j];

	for (int b = 1; b < (1 << 10); ++b) {
		bitset<10> bit = b;
		int benefit = 0;
		for (int i = 0; i < n; ++i) {
			int d = 0;
			for (int j = 0; j < 10; ++j) if (bit[9 - j] && f[i][j]) d++;
			benefit += p[i][d];
		}
		ans = max(ans, benefit);
	}
	cout << ans << endl;
}