#include<bits/stdc++.h>
using namespace std;
int n,m,f[100005],ans,a[100005],mid,b[100005],c[100005];
long long num;
void add(int x,int y){
	for(;x<=m;x+=x&-x)f[x]+=y;
}
int ask(int x){
	int sum=0;
	for(;x;x-=x&-x)sum+=f[x];
	return sum;
}
long long calc(){
    long long sum=0;
    b[0]=0;
	memset(f,0,sizeof(f));
    for(int i=1;i<=n;i++){
		b[i]=b[i-1]+(a[i]<=mid?1:-1);
		c[i]=b[i];
	}
	m=n+1;
    c[m]=0;
	sort(c+1,c+m+1);
	m=unique(c+1,c+m+1)-(c+1);
    for(int i=0;i<=n;i++)b[i]=lower_bound(c+1,c+m+1,b[i])-c;
    add(b[0],1);
    for(int i=1;i<=n;i++){
		sum+=(long long)ask(b[i]-1);
		add(b[i],1);
	}
	return sum;
}
int main(){
    scanf("%d",&n);
	num=n*(long long)(n+1)>>1;
	num=(num>>1)+1;
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    int L=1,R=1e9;
    while(L<=R){
        mid=L+R>>1;
        if(calc()>=num){
			ans=mid;
			R=mid-1;
        }
		else L=mid+1;
    }
    printf("%d\n",ans);
    return 0;
}