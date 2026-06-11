//#include<bits/stdc++.h>
#include<iostream>
#include<iomanip>
#include<cstring>
#include<stack>
#include<vector>
//#include<conio.h>
#include<string>
#include<map>
#include<cstdlib>
#include<queue>
#include<math.h>
#include<time.h>
#include<set>
#include<cstdio>
#include<stdio.h>
#include<algorithm>
using namespace std;
inline int read(){
	int ans=0,flag=1;
	char ch=getchar();
	while((ch>'9'||ch<'0')&&ch!='-') ch=getchar();
	if(ch=='-') flag=-1,ch=getchar();
	while(ch>='0'&&ch<='9'){
		ans=(ans<<1)+(ans<<3)+(ch^'0');
		ch=getchar();
	}
	return ans*flag;
}
int a,b,c,x,ans;
int main(){
	a=read(),b=read(),c=read(),x=read();
	for(int i=0;i<=a;i++)
		for(int j=0;j<=b;j++)
			for(int k=0;k<=c;k++)
				if(i*500+j*100+k*50==x) ans++;
	printf("%d\n",ans);
	return 0;
}
