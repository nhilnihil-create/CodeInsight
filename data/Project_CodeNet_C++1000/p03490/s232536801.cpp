#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#define maxn 16005
using namespace std;
int n,nx,ny;
char s[maxn];
int dp1[2][maxn],now1,pre1=1;
int dp2[2][maxn],now2,pre2=1;
int main()
{
	scanf("%s",s+1); n=strlen(s+1);
	scanf("%d%d",&nx,&ny);
	int pos;
	int sx=0,sy=0;
	for(pos=1;pos<=n;pos++)
	{
		if(s[pos]=='F')
			sx++;
		else
			break;
	}
	if(pos>n)
	{
		if(sx==nx && sy==ny)
			printf("Yes\n");
		else
			printf("No\n");
		return 0;
	}
	int f=0;// 0 表示在向x边，1表示在向y
	dp1[0][sx+8000]=1;
	dp2[0][sy+8000]=1;
	for(int i=pos;i<=n;i++)
	{
		if(s[i]=='T')
		{
			f^=1;
			continue;
		}
		int cnt=0;
		while(s[i]=='F' && i<=n)
			cnt++,i++;
		i--;
//		cout<<"its "<<i<<endl;
		if(f==1)
		{
//			cout<<"this is y "<<endl;
			swap(now2,pre2);
			memset(dp2[now2],0,sizeof(dp2[now2]));
			for(int j=0;j<=16000;j++)
			if(dp2[pre2][j])
			{
				if(j-cnt>=0)
					dp2[now2][j-cnt]=1;//,cout<<j-cnt<<endl;
				if(j+cnt<=16000)
					dp2[now2][j+cnt]=1;//,cout<<j+cnt<<endl;
			}
		}
		else
		{
//			cout<<"this is x"<<endl;
			swap(now1,pre1);
			memset(dp1[now1],0,sizeof(dp1[now1]));
			for(int j=0;j<=16000;j++)
			if(dp1[pre1][j])
			{
				if(i-cnt>=0)
					dp1[now1][j-cnt]=1;//,cout<<j-cnt<<endl;
				if(i+cnt<=16000)
					dp1[now1][j+cnt]=1;//,cout<<j+cnt<<endl;
			}
		}
	}
	if(dp1[now1][nx+8000] && dp2[now2][ny+8000])
		printf("Yes\n");
	else 
		printf("No\n");
}
