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
const ll INF = (1 << 31);
template<typename A, size_t N, typename T>
void Fill(A(&array)[N], const T & val) {
    std::fill((T*)array, (T*)(array + N), val);
}
const int MAX = 510000;
const int MOD = 1000000007;
int main() {
	string s; cin >> s;
	int l = 0, r = s.size() - 1,ans = 0;
	while (l + 1 <= r) {
		if (s[l] != s[r] && s[l] != 'x' && s[r] != 'x') {
			cout << -1 << endl;
			return 0;
		}
		if (s[l] == s[r]) {
			l++; r--;
		}
		else if (s[l] == 'x') {
			l++; ans++;
		}
		else {
			r--; ans++;
		}
	}cout << ans << endl;
}