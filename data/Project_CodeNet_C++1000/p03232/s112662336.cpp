#include<cstring>
#include<cstdio>
#include<iostream>
#include<algorithm>
#define N 100010
#define LL long long
#define CK 1000000007
using namespace std;

int i,n;
LL Ans;
LL a[N],p[N],s[N],b[N];

inline void Ready(){
	int i=0;
	for (p[1]=1,i=2;i<=n;i++)	p[i]=((CK-CK/i)*p[CK%i])%CK;
}

inline void Work(){
	int i=0;
	for (i=1;i<=n;i++)	s[i]=(s[i-1]+p[i])%CK;
	for (i=1;i<=n;i++)	b[i]=(s[i]+s[n-i+1]-1)%CK;
	for (i=1;i<=n;i++)	Ans+=(a[i]*b[i])%CK;
	for (i=1;i<=n;i++)	Ans=(Ans*i)%CK;
	cout<<Ans<<endl;
}

int main(){
	scanf("%d",&n);
	for (i=1;i<=n;i++)	cin>>a[i];
	Ready();	Work();
	return 0;
}