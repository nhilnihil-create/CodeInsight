/*************************************************************************
	> File Name: mid.cpp
	> Author: The-Out-Land
	> Mail: 2264454706@qq.com 
	> Created Time: 2019年10月22日 星期二 08时46分58秒
 ************************************************************************/

#include<bits/stdc++.h>

#define enter putchar('\n')
#define space putchar(' ')
#define M 4000100
#define N 2010

using namespace std;

int n,a[N];

bitset<M>ans;

bitset<M>reans;

inline int read(){
	int x=0;char c=getchar();bool y=1;
	for(;c<'0' || c>'9';c=getchar()) if(c=='-') y=0;
	for(;c>='0' && c<='9';c=getchar()) x=(x<<1)+(x<<3)+c-48;
	if(y) return x;
	return -x;
}

inline void Input(){
	n=read();
	for(int i=1;i<=n;i++)
	a[i]=read();
	return;
}

inline void solve(){
	int sum=0;
	ans=1;
	for(int i=1;i<=n;i++)
	{
		sum+=a[i];
		ans=(ans<<a[i])|ans;
		ans[a[i]]=1;
	}

	int judge=ans.count(),tot=0;


	for(int i=1;i<=sum;i++)
	{
		if(ans.test(i)) tot++;
		if(tot>=judge/2) {printf("%d\n",i);exit(0);}
	}
	return;
}

int main(){
	//freopen("mid.in","r",stdin);
	//freopen("mid.out","w",stdout);
	Input();
	solve();
	return 0;
}