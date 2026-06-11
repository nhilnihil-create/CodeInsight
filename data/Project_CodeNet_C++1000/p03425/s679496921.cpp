#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<iomanip>
#include<sstream>
#include<map>
#include<set>
#include<cmath>
using namespace std;
#define rep(i,n) for(int i = 0;i < n;i++)
#define req(i,n) for(int i = 1;i <=n;i++)
#define rrep(i,n) for(int i = n -1;i >= 0;i--)
#define ALL(a) a.begin(),a.end()
typedef long long ll;
typedef long double ld;
const ll MOD =  1000000007;
const ll INF =  1LL << 60;
int n, m, x, y;ll z = 0, w, h, sum = 0, ans = 0;
template<typename A, size_t N, typename T>
void Fill(A(&array)[N], const T & val) {
    std::fill((T*)array, (T*)(array + N), val);
}
int main(void) {
	cin >> n; vector<ll> k(5, 0); string s;
	rep(i, n) {
		cin >> s;
		if (s[0] == 'M') k[0]++;
		else if (s[0] == 'A')k[1]++;
		else if (s[0] == 'R')k[2]++;
		else if (s[0] == 'C') k[3]++;
		else if (s[0] == 'H') k[4]++;
	}
	rep(i, 1 << 5) {
		int cnt = 0; sum = 1;
		rep(j, 5) {
			if (i & (1 << j)) cnt++;
		}
		if (cnt != 3) continue;
		rep(j, 5) {
			if (i & (1 << j))sum *= k[j];
		}
		ans += sum;
	}cout << ans << endl;
}
