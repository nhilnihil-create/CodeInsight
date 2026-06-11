#include <bits/stdc++.h>
#pragma GCC optimize(2)
#define ll long long
#define ull unsigned long long

using namespace std;

inline ll in()
{
	ll Req = 0, wX = 0; char ch;
	while (!isdigit(ch)) {wX |= (ch == '-'); ch = getchar();}
	while (isdigit(ch)) {Req = (Req << 3) + (Req << 1) + (ch ^ 48); ch = getchar();}
	return wX ? -Req : Req;
}

inline void out(ll x)
{
	register short Pxn[20], Ry = 0;
	if (x == 0) putchar('0');
	if (x < 0) putchar('-'), x = -x;
	while (x != 0) Pxn[Ry] = x % 10, x /= 10, Ry++;
	for (int i = Ry - 1; i >= 0; i--) putchar(Pxn[i] + '0');
}

int main()
{

	int a = in(), b = in();
	if (a + b == 15) puts("+");
	else if (a * b == 15) puts("*");
	else puts("x");

  return 0;

}

