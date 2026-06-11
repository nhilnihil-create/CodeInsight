#include<bits/stdc++.h>
#define ll long long
#define re register
using namespace std;
const int maxn=17;
template<typename T> void read(T &x){
	T f=1;x=0;
	char c=getchar();
	while(c<'0' || c>'9'){if(c=='-') f=-1;c=getchar();}
	while(c>='0' && c<='9'){x=(x<<3)+(x<<1)+c-48;c=getchar();}
	x*=f;
}
int n;
ll a[maxn][maxn];
ll f[1<<17];
ll pre[1<<17];
int main(){
	read(n);
	for(re int i=1;i<=n;i++){
		for(re int j=1;j<=n;j++){
			read(a[i][j]);
		}
	} 
	for(re int i=1;i<=(1<<n)-1;i++){
		for(re int j=1;j<=n;j++){
			for(re int k=1;k<=n;k++){
				if(i&(1<<(k-1)) && i&(1<<(j-1))){
					pre[i]+=a[j][k];
				}
			}
		}
	}
	for(re int i=1;i<=(1<<n)-1;i++){
		f[i]=pre[i];
		for(re int j=i;j;j=(j-1)&i){
			int k=j^i;
			f[i]=max(f[i],f[j]+f[k]);
		}
	}
	cout<<f[(1<<n)-1]/2<<endl;
	return 0;
}
