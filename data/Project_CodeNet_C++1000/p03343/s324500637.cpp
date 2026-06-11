
// Problem : E - Range Minimum Queries
// Contest : AtCoder Regular Contest 098
// URL : https://atcoder.jp/contests/arc098/tasks/arc098_c
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include "bits/stdc++.h"
using namespace std;

// begin of indexed_set
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> indexed_multiset;
// end of indexed_set

using ll = long long;
#define cerr if(1)cerr
#define size(x) (int)x.size()
#define all(x) x.begin(), x.end()

const int N = 2002, inf = 1e9 + 7;																																																																																								void read(int&n){n=0;while(1){char c=getchar();if(c==' '||c=='\n')break;n=(n<<1)+(n<<3)+c-'0';}}void read(ll&n){n=0;while(1){char c=getchar();if(c==' '||c=='\n')break;n=(n<<1)+(n<<3)+c-'0';}}void write(int n){if(n>9)write(n/10),putchar(n%10+'0');else putchar(n+'0');}void write(ll n){if(n>9)write(n/10),putchar(n%10+'0');else putchar(n+'0');}template<class F,class... Ts>void read(F&f,Ts&...ts){read(f);read(ts...);}template<class F,class... Ts>void write(F&f,Ts&...ts) {write(f);putchar(' ');write(ts...);}template<class...Ts>void writeln(const Ts&...ts){write(ts...);putchar('\n');}

int n, k, q, ans = inf, a[N], l[N];
indexed_multiset im;

int main() {
	read(n, k, q);
	for (int i = 1; i <= n; i++) {
		read(a[i]);
	}
	for (int j = 1; j <= n; j++) {
		im.clear();
		int pre = 1;
		for (int i = 1; i <= n; i++) {
			if (a[i] < a[j]) {
				im.clear();
				pre = i + 1;
			} else {
				im.insert({a[i], i});
				l[i] = i - pre + 1 - im.order_of_key({a[i], i});
			}
		}
		pre = n;
		im.clear();
		vector<int> v;
		for (int i = n; i >= 1; i--) {
			if (a[i] < a[j]) {
				im.clear();
				pre = i - 1;
			} else {
				im.insert({a[i], i});
				int cur = l[i] + pre - i + 1 - im.order_of_key({a[i], 0}) - 1;
				if (cur >= k) {
					v.push_back(a[i]);
				}
			}
		}
		if (size(v) >= q) {
			sort(all(v));
			ans = min(ans, v[q - 1] - v[0]);
		}
	}
	write(ans);
}
