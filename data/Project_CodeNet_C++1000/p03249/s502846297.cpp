#include<bits/stdc++.h>
#define mo 998244353
#define ny 499122177
#define maxn 1000000000000000000LL
#define pi 3.1415926535898
#define eps 1e-9 
using namespace std;
long long read(){
    long long xx=0,flagg=1;
    char ch=getchar();
    while((ch<'0'||ch>'9')&&ch!='-')
        ch=getchar();
    if(ch=='-'){
        flagg=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        xx=xx*10+ch-'0';
        ch=getchar();
    }
    return xx*flagg;
}
void pus(long long xx,long long flagg){
    if(xx<0){
        putchar('-');
        xx=-xx;
    }
    if(xx>=10)
        pus(xx/10,0);
    putchar(xx%10+'0');
    if(flagg==1)
        putchar(' ');
    if(flagg==2)
        putchar('\n');
    return;
}
long long n,i,x,zz[100005],sum[100005],sum2[100005];
struct nyh{
	long long x,id;
}o[100005];
map<long long,long long> mp;
bool cmp(nyh u,nyh v){
	return u.x<v.x;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read();
	for(i=1;i<=n;i++){
		o[i].x=read();
		o[i].id=i;
	}
	sort(o+1,o+n+1,cmp);
	for(i=1;i<=n;i++){
		mp[o[i].x]=i;
		sum[i]=1;
	}
	for(i=n;i>=2;i--){
		x=o[i].x-n+sum[i]*2;
		if(mp[x]!=0&&mp[x]<i){
			zz[i]=mp[x];
			sum[zz[i]]+=sum[i];
			sum2[zz[i]]+=sum[i]+sum2[i];
		}
		else{
			pus(-1,2);
			return 0;
		}
	}
	if(sum2[1]!=o[1].x){
		pus(-1,2);
		return 0;
	}
	for(i=n;i>=2;i--){
		pus(o[zz[i]].id,1);
		pus(o[i].id,2);
	}
	return 0;
}