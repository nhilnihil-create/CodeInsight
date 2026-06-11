#include<bits/stdc++.h>
#define maxn 3003
using namespace std;
inline int read()
{
	char x = getchar();
	int lin = 0, f = 1;
	while(x < '0' || x > '9')
	{
		if(x == '-') f = -1;
		x = getchar();
	}
    while(x >= '0' && x <= '9')
	{
		lin = (lin << 1) + (lin << 3) + x - '0';
		x = getchar();
	}
	return lin * f;
}
#define PII pair<int,int>
#define fir first
#define sec second
#define ma(a,b) make_pair(a,b)
#define db double
int n,s[maxn][maxn];
signed main(){
	n = read();
	int k = 1 + 8 * n;
	
	if(int(sqrt(k)) * int(sqrt(k)) != k || !(int(sqrt(k)) & 1))
	{
		cout << "No";
		return 0;
	}
	k = int(sqrt(k)) - 1 >> 1;
	printf("Yes\n%d\n",k + 1);
	int up = 0,now = 0;
	for(int i = 1; i <= k + 1; i++)
	{
		for(int j = i; j <= k; j++)
			s[i][j] = ++now;
		for(int j = i + 1; j <= k + 1; j++)
			s[j][i] = ++up;
	}
	for(int i = 1; i <= k + 1; i++)
	{
		printf("%d ",k);
		for(int j = 1; j <= k; j++)
		{
			printf("%d ",s[i][j]);
		}
		puts("");
	}
}