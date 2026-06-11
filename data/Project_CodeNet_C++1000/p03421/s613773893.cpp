#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define maxn 300005
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
#define mp make_pair
#define ff first
#define ss second

int n,a,b;

inline int read(){
	int x=0,f=1; char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') f=-1;
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x*f;
}

int main(){
	cin>>n>>a>>b;
	if (1ll*a*b<n){puts("-1"); return 0;}
	if (a+b-1>n){puts("-1"); return 0;}
	if (a>b){
		while (n-a>=b-1&&n>0){
			for (int i=n-a+1;i<=n;i++) printf("%d ",i);
			--b,n-=a;
		}
		if (n>0) for (int i=b;i<=n;i++) printf("%d ",i);
		while (--b>0) printf("%d ",b); puts("");
	}
	else{
		int pp=n;
		while (n-b>=a-1&&n>0){
			for (int i=n-b+1;i<=n;i++) printf("%d ",pp-i+1);
			--a,n-=b;
		}
		if (n>0) for (int i=a;i<=n;i++) printf("%d ",pp-i+1);
		while (--a>0) printf("%d ",pp-a+1); puts("");
	}
	return 0;
}
