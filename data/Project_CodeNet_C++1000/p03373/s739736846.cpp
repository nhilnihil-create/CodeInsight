
// Problem : C - Half and Half
// Contest : AtCoder Regular Contest 096
// URL : https://atcoder.jp/contests/arc096/tasks/arc096_a
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define cerr if(1)cerr
#define size(x) (int)x.size()
#define all(x) x.begin(), x.end()

const int N = 1e6 + 1, mod = 1e9 + 7, inf = 2e9;																																																																																								void read(int&n){n=0;while(1){char c=getchar();if(c==' '||c=='\n')break;n=(n<<1)+(n<<3)+c-'0';}}void read(ll&n){n=0;while(1){char c=getchar();if(c==' '||c=='\n')break;n=(n<<1)+(n<<3)+c-'0';}}void write(int n){if(n>9)write(n/10),putchar(n%10+'0');else putchar(n+'0');}void write(ll n){if(n>9)write(n/10),putchar(n%10+'0');else putchar(n+'0');}template<class F,class... Ts>void read(F&f,Ts&...ts){read(f);read(ts...);}template<class F,class... Ts>void write(F&f,Ts&...ts) {write(f);putchar(' ');write(ts...);}template<class...Ts>void writeln(const Ts&...ts){write(ts...);putchar('\n');}

int a, b, c, x, y, ans = inf;

int main() { cin.tie(0)->sync_with_stdio(0);
	read(a, b, c, x, y);
	for(int i = 0; i <= max(x,y); i++) {
		ans = min(ans, i * (c << 1) + max(0, x - i) * a + max(0, y - i) * b);
	}
	write(ans);
}
