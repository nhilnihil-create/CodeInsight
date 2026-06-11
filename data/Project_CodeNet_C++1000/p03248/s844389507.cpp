#include<bits/stdc++.h>
#define ll long long
#define re register
#define ull unsigned ll
using namespace std;
inline int read(){
	int s=0,t=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')t=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')s=(s<<3)+(s<<1)+(ch^48),ch=getchar();
	return s*t;
}
const int N=1e5+5;
char s[N];
int n,a[N];
void Exit(){puts("-1"),exit(0);}
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	scanf("%s",s+1),n=strlen(s+1);
	for(int i=1;i<=n;i++)a[i]=s[i]-'0';
	for(int i=0;i<=n;i++)if(a[i]^a[n-i])Exit();
	if(!a[1])Exit();a[n]=1;
	int tot=1,lst=1;
	for(int i=2;i<=n;i++)
	if(a[i]){
		printf("%d %d\n",i,tot);
		for(int j=lst+1;j<i;j++)printf("%d %d\n",i,++tot);
		lst=tot=i;
	}
	return 0;
}
