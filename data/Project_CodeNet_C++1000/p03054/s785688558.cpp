#include<cstdio>
#include<algorithm>
using namespace std;
int H, W;
int n;
int r0, c0;
char S[200200], T[200200];
int main()
{
	scanf("%d%d%d", &H, &W, &n);
	scanf("%d%d", &r0, &c0);
	scanf("%s%s", &S[1], &T[1]);
	int sr = 1, er = H, sc = 1, ec = W; // safe area at the end
	bool flag = false;
	for (int i = n; i >= 1; i--)
	{
		if (T[i] == 'L') ec++; // extend safe area to right
		else if (T[i] == 'R') sc--; // to left
		else if (T[i] == 'U') er++; // to below
		else sr--; // to above
		sr = max(1, sr); sc = max(1, sc);
		er = min(H, er); ec = min(W, ec);

		if (S[i] == 'L') sc++; // shrink safe area from left
		else if (S[i] == 'R') ec--; // from right
		else if (S[i] == 'U') sr++; // from above
		else er--; // from below
		if (sc > ec || sr > er) { flag = true; break; }
	}
	if (!flag && sr <= r0 && r0 <= er && sc <= c0 && c0 <= ec) printf("YES\n");
	else printf("NO\n");
	return 0;
}
