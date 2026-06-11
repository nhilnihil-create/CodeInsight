#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
char s[200010];
int t[200010];
int f[200010];
int minn[(1<<26)+1];
int main()
{
	scanf("%s",s+1);
	for (int i=1;i<=strlen(s+1);i++)
		t[i]=t[i-1],t[i]^=(1<<(s[i]-'a'));
	for (int i=0;i<=(1<<26)-1;i++) minn[i]=1e9;
	minn[0]=0;
	for (int i=1;i<=strlen(s+1);i++)
	{
		//cout<<"t[i]="<<t[i]<<endl;
		f[i]=1e9;
		for (int j=0;j<=25;j++)
			f[i]=min(f[i],minn[t[i]^(1<<j)]+1);//,cout<<(t[i]^(1<<j))<<" "<<minn[t[i]^(1<<j)]<<endl;
		f[i]=min(f[i],minn[t[i]]+1);
		minn[t[i]]=min(minn[t[i]],f[i]);
	}
	printf("%d",f[strlen(s+1)]);
}