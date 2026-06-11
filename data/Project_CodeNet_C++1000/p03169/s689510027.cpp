#include <bits/stdc++.h>
#define ll long long
#define re register
#define IL inline
using namespace std;
const int maxn=300+5;
template<typename T> void fread(T &x){
	T f=1;x=0;
	char s=getchar();
	while(s<'0' || s>'9'){if(s=='-') f=-1;s=getchar();}
	while(s>='0' && s<='9'){x=(x<<3)+(x<<1)+s-48;s=getchar();}
	x*=f;
}
int n,a[maxn],d[4];
double f[305][605][905];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d",&n);
	for(re int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		d[a[i]]++;
	} 
	for(re int i=0;i<=d[3];i++){
		for(re int j=0;j<=d[2]+d[3];j++){
			for(re int k=0;k<=d[1]+d[2]+d[3];k++){
				double tot=i+j+k;
				if(i) f[i][j][k]+=(double) f[i-1][j+1][k]*i/tot;
				if(j) f[i][j][k]+=(double) f[i][j-1][k+1]*j/tot;
				if(k) f[i][j][k]+=(double) f[i][j][k-1]*k/tot;
				if(tot) f[i][j][k]+=(double) n/tot; 
			}
		}
	}
	cout<<fixed<<setprecision(10)<<f[d[3]][d[2]][d[1]]<<endl;
	return 0;
}
