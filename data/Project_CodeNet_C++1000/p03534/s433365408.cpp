#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;

const int N = 100010;
char s[N];
int n, cnta, cntb, cntc;

int main()
{
	scanf("%s", s+1); int n = strlen(s+1);
	for (int i = 1; i <= n; i ++){
		if (s[i] == 'a') cnta ++;
		if (s[i] == 'b') cntb ++;
		if (s[i] == 'c') cntc ++;
	}
	//printf("%d %d %d\n", cnta, cntb, cntc);
	if ((abs(cnta-cntb) <= 1) && (abs(cnta-cntc) <= 1) && (abs(cntb-cntc) <= 1)) puts("YES");
	else puts("NO");
	return 0;
}