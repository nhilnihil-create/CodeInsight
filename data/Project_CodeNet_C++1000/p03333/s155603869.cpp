/* Your prologue will be the story. */
/* Copyright by HenryLi */
#include<iostream>
#include<algorithm>
#include<queue>
#include<string>
#include<map>
#include<vector>
#include<set>
#include<sstream>
#include<stack>
#include<ctime>
#include<cmath>
#include<cctype>
#include<climits>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<iomanip>
#include<bitset>
#include<complex>
using namespace std;
template <class _T> inline void read(_T &_x) {
	int _t; bool _flag=false;
	while((_t=getchar())!='-'&&(_t<'0'||_t>'9')) ;
	if(_t=='-') _flag=true,_t=getchar(); _x=_t-'0';
	while((_t=getchar())>='0'&&_t<='9') _x=_x*10+_t-'0';
	if(_flag) _x=-_x;
}
typedef long long LL;
const int maxn = 100010;
int n, l[maxn], r[maxn];
int main() {
	//freopen("C.in","r",stdin);
	//freopen("C.out","w",stdout);
	read(n);
	for (int i = 1; i <= n; ++i) read(l[i]), read(r[i]);
	sort(l, l + n + 1), sort(r, r + n + 1);
	LL ans = 0;
	for (int i = 0; i <= n; ++i) ans += max(l[n - i] - r[i], 0);
	cout << ans * 2 << endl;
	return 0;
}
