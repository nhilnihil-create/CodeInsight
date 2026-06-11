#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
#define ge getchar 
#define pun putchar('\n')
#define pu putchar
#define puk putchar(' ')
char c;
int n,i,a,b,l,r,e,z,rr,x[120],y[120],d[120],h[120];
bool o,w;
ll g[50];
int sri(){c=ge();int x=0;while(c<'0')c=ge();while(c>='0')x=(x<<3)+(x<<1)+c-'0',c=ge();return x;}
void sc(ll x){int l=0;if(x==0)g[l=1]=0;while(x)g[++l]=x%10,x/=10;for(;l;l--)putchar(g[l]+'0');}
int main(){
	n=sri();rr=1000001000;w=1;
	for(i=1;i<=n;i++)x[i]=sri(),y[i]=sri(),h[i]=sri();
	for(a=0;a<=100&&w;a++){
		for(i=1;i<=n;i++)if(x[i]>a)d[i]=x[i]-a;else d[i]=a-x[i];
		for(b=0;b<=100&&w;b++){l=0;r=rr;o=1;
			for(i=1;i<=n;i++){
				if(y[i]>b)e=y[i]-b;else e=b-y[i];
				if(h[i]){
					z=h[i]+e+d[i];
					if(l<=z&&r>=z)l=r=z;else{o=0;break;}
				}else{
					z=e+d[i];
					if(r>z){
						r=z;if(l>r){o=0;break;}
					}
				}
			}
			if(o){w=0;
				sc(a);puk;sc(b);puk;sc(r);pun;
			}
		}
	}
    return 0;
}