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

inline string strin()
{
	char ch = getchar(); string ret = "";
	while (ch == ' ' || ch == '\n') ch = getchar();
	while (ch != ' ' && ch != '\n') ret += ch, ch = getchar();
	return ret;
}

int main()
{

	string s = strin();
	int w = in(), len = s.length();
	for (int i = 0; i < len; i += w)
		putchar(s[i]);
	putchar('\n');

  return 0;

}

