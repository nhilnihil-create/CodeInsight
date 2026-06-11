#include <bits/stdc++.h>
using namespace std;
const int maxn = 20000 + 10;
const int limt = 30000;
int ans[maxn],vis[limt];
long long gcd(int a,int b)
{
	return b == 0 ? a : gcd(b,a%b);
}
int main()
{
		int n;
		scanf("%d",&n);
		memset(vis,0,sizeof(vis));
		int sum = 0 ,cnt = 0;
		for(int i = 1 ; i < limt ;i ++)
		{
			if(i % 2 == 0 || i % 3 == 0)
			{
				cnt++;
				printf("%d ",i);
				vis[i] = 1;
				sum += i;
			}
			if(cnt == n-1) break;
		}
		int sum1 = sum%2;
		int sum2 = sum%3;
		for(int i = 1 ; i <= limt;i++)
		{
			if((sum1+i)%2==0&&(sum2+i)%3==0 && !vis[i] && gcd(sum,i)!=1)
			{
				printf("%d ",i);
				break;
			}
		}
		puts("");
	}