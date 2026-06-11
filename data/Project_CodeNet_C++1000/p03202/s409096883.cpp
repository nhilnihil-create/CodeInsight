#include<ctime>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<set>
#define file(x)freopen(x".in","r",stdin);freopen(x".out","w",stdout)
#define rt register int
#define l putchar('\n')
#define ll long long
#define r read()
using namespace std;
inline ll read(){
    ll x=0;char zf=1;char ch=getchar();
    while(ch!='-'&&!isdigit(ch))ch=getchar();
    if(ch=='-')zf=-1,ch=getchar();
    while(isdigit(ch))x=x*10+ch-'0',ch=getchar();return x*zf;
}
void write(ll y){if(y<0)putchar('-'),y=-y;if(y>9)write(y/10);putchar(y%10+48);}
void writeln(const ll y){write(y);putchar('\n');}
int k,m,n,x,y,z,cnt,ans;
int a[200010],num[200010],sta[200010],gg[200010],tot,top;
set<int>s;
bool check(int x){
	memset(num,0,sizeof(num));tot=0;
	for(rt i=1;i<=min(n+1,a[1]);i++)num[i]=1;top=0;s.clear();
	for(rt i=2;i<=n;i++)if(a[i]<=n+1){
		int pl=a[i];num[pl]++;
		while(num[pl]>=x){
			if(pl==1)return 0;
			num[pl]=1,num[pl-1]++;s.insert(pl-1);
			pl--;
		}
		while(top&&sta[top]>a[i]){
			num[sta[top]]=0;
			top--;
		}
		for(auto j:s)if(j>a[i])num[j]=0,gg[++tot]=j;
		for(rt j=1;j<=tot;j++)s.erase(gg[j]);tot=0;
		sta[++top]=a[i];
	}
	return 1;
}
int main(){
//	freopen("C.in","r",stdin);
	n=r;bool fla=1;
	for(rt i=1;i<=n;i++){
		a[i]=r;
		if(i>1&&a[i]<=a[i-1])fla=0;
	}
	if(fla)return cout<<1,0;
	int L=2,R=n;
	while(L<=R){
		const int mid=L+R>>1;
		if(check(mid+1))ans=mid,R=mid-1;
		else L=mid+1;
	}
	cout<<ans;
	return 0;
}
