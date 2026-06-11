#include<stdio.h>
#include<algorithm>
using namespace std;
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
int n,a[110000],l,r,mi,f[220000];
long long m;
inline void add(int x){
	while (x<=n+n){
		f[x]++;
		x+=x&(-x);
	}
}
inline long long ask(int x){
	long long ans=0;
	while (x){
		ans+=f[x];
		x-=x&(-x);
	}
	return ans;
}
inline bool che(int x){
	int s=n+1;long long ans=0;//s=n TLE
	fo(i,0,n+n) f[i]=0;
	add(s);
	fo(i,1,n){
		if (a[i]>=x) s++;else s--;
		ans+=ask(s);
		add(s);
	}
	return ans>=m;
}
int main(){
	scanf("%d",&n);
	fo(i,1,n) scanf("%d",&a[i]);
	m=n*1ll*(n+1)/2;
	m=(m+1)/2;
	l=0x7fffffff;r=0;
	fo(i,1,n){
		if (a[i]<l) l=a[i];
		if (a[i]>r) r=a[i];
	}
	l--;r++;
	while (l+3<r){
		mi=(l+r)>>1;
		if (che(mi)) l=mi+1;else r=mi-1;
	}
	fd(i,r+1,l-1) if (che(i)){//che(mi)!!!
		printf("%d\n",i);
		return 0;
	}
	return 0;
}