
// Problem : D - Median of Medians
// Contest : AtCoder Regular Contest 101
// URL : https://atcoder.jp/contests/arc101/tasks/arc101_b
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include "bits/stdc++.h"
using ll = long long;
using namespace std;
#define cerr if(1)cerr
#define size(x) (int)x.size()
 
const int N = 1e5 + 1, inf = 1e9;																																																																																								void read(int&n){n=0;while(1){char c=getchar();if(c==' '||c=='\n')break;n=(n<<1)+(n<<3)+c-'0';}}void read(ll&n){n=0;while(1){char c=getchar();if(c==' '||c=='\n')break;n=(n<<1)+(n<<3)+c-'0';}}void write(int n){if(n>9)write(n/10),putchar(n%10+'0');else putchar(n+'0');}void write(ll n){if(n>9)write(n/10),putchar(n%10+'0');else putchar(n+'0');}template<class F,class... Ts>void read(F&f,Ts&...ts){read(f);read(ts...);}template<class F,class... Ts>void write(F&f,Ts&...ts) {write(f);putchar(' ');write(ts...);}template<class...Ts>void writeln(const Ts&...ts){write(ts...);putchar('\n');}

int n, r[N], a[N], p[N], _cnt[2 * N + 1];
int* cnt = _cnt + N;

bool check(int k) {
	ll ans = 0;
	for (int i = -1e5; i <= 1e5; i++) {
		cnt[i] = 0;
	}
	k++;
	int now = 1, sum = 0;
	cnt[0] = 1;
	for (int i = 1; i <= n; i++) {
		if (a[i] >= k) {
			sum++;
			now += cnt[sum];
		} else {
			now -= cnt[sum];
			sum--;
		}
		cnt[sum]++;
		ans += now;
		now++;
	}
	return 1ll * n * (n + 1) / 2 - ans >= 1ll * n * (n + 1) / 4 + 1;
}
 
int main() { cin.tie(0)->sync_with_stdio(0);
	read(n);
	map<int, int> m;
	int ca = 0;
	for (int i = 1; i <= n; i++) {
		read(a[i]);
		m[a[i]] = 0;
	}
	for (auto& x : m) {
		x.second = ++ca;
	}
	for (int i = 1; i <= n; i++) {
		r[m[a[i]]] = a[i];
		a[i] = m[a[i]];
	}
	int ans = 0;
	for (int j = log2(n); j >= 0; j--) {
		ans += 1 << j;
		if (check(ans)) {
			ans -= 1 << j;
		}
	}
	cout << r[ans + 1];
}