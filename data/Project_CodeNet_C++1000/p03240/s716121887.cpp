#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cmath>
#include<stack>
#include<queue>
using namespace std;
typedef long long ll;

const int maxn = 110;

ll n,sumd,sumh;
ll cx,cy,H;
ll x[maxn],y[maxn],h[maxn],dis[maxn];

ll read(){ ll s=0,f=1; char ch=getchar(); while(ch<'0' || ch>'9'){ if(ch=='-') f=-1; ch=getchar(); } while(ch>='0' && ch<='9'){ s=s*10+ch-'0'; ch=getchar(); } return s*f; }

int main(){
	n=read();
	for(int i=1;i<=n;i++) x[i]=read(),y[i]=read(),h[i]=read();
	
	for(ll i=0;i<=100;i++){
		for(ll j=0;j<=100;j++){
			ll th = 0,tr = 1;
			memset(dis,0,sizeof(dis));
			for(int k=1;k<=n;k++){
				dis[k] = abs(x[k] - i) + abs(y[k] - j);
				if(h[k]!=0)	th = h[k] + dis[k];
			}
			for(int k=1;k<=n;k++){
				if(h[k]!=0){
					if((h[k] + dis[k]) != th){
						tr = 0; break;
					}
				}else{
					if(dis[k] < th){
						tr = 0; break;
					}
				}
			}
			if(!tr) continue;
			else{
				printf("%lld %lld %lld\n",i,j,th);
				return 0;
			}
		}
	}
	
	
	return 0;
}