#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<functional>
#include<vector>
#include<queue>
using namespace std;
#define f(i,n) for(int i=0;i<(int)n;i++)
#define MOD 1000000009

int main(void){
	char a[100000];
	f(i, 100000)a[i] = 0;
	int k;
	int n;
	int x, y, z;
	int ans = 0;
	bool m = true;

	scanf("%s", a);
	n = strlen(a);
	x = 0;
	y = 0;
	z = 0;
	k = n / 3;
	f(i, n){
		if (a[i] == 'a')x++;
		if (a[i] == 'b')y++;
		if (a[i] == 'c')z++;
	}
	if (x < k||k + 1 < x)m = false;
	if (y < k||k + 1 < y)m = false;
	if (z < k||k + 1 < z)m = false;

	if (m)printf("YES\n");
	else printf("NO\n");

	return 0;
}