#include <iostream> 
#include<vector>
#include<algorithm>
#include<map>
#include<iomanip>
#include<set>
#include<queue>
#include<deque>
#include<iomanip>
#include<sstream>
#include<cmath>
#include<tuple>
#include<bitset>
using namespace std;
#define rep(i, n) for (ll i = 0; i < (int)(n); i++)
#define req(i,n) for(ll i = 1;i <=  n; i++)
#define rrep(i,n) for(ll i = n -1;i >= 0;i--)
#define ALL(obj) begin(obj), end(obj)
typedef long long int ll;
typedef long double ld;
const ll INF = 1e18;
template<typename A, size_t N, typename T>
void Fill(A(&array)[N], const T & val) {
	std::fill((T*)array, (T*)(array + N), val);
}ll n, S,k; vector<ll> a; string s;
const ll mod = 998244353;
int main(void) {
	cin >> n >> k  >> s;
	int sum = 1; vector<int> a;;
	int bit = s[0] - '0';
	if (bit == 0) a.push_back(0);
	rep(i, n - 1) {
		if (s[i + 1] == s[i]) sum++;
		else {
			a.push_back(sum);
			sum = 1; 
		}
	}
	a.push_back(sum); int ans = 0;
	if (s[n - 1] == '0') a.push_back(0);
	bit = 1 - bit;
	rep(i, a.size()-1) a[i + 1] += a[i];
	for (int i = 2 * k; i < a.size(); i += 2) {
		if (i == 2 * k) ans = max(ans, a[i]);
		else ans = max(ans, a[i] - a[i - 2 * k - 1]);
	}if (2 * k >= a.size()) ans = a[a.size()-1];
	cout << ans << endl;
}