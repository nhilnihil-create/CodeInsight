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
int n,u,v;
ll p=1000000007,f,w[200008],g[50];
int sri(){c=ge();int x=0;while(c<'0')c=ge();while(c>='0')x=(x<<3)+(x<<1)+c-'0',c=ge();return x;}
void sc(ll x){int l=0;if(x==0)g[l=1]=0;while(x)g[++l]=x%10,x/=10;for(;l;l--)putchar(g[l]+'0');}
int main(){
	n=sri();f=1;
	while(n--){
		u=sri();
		if(u!=v){
			f+=w[u];if(f>=p)f-=p;
			w[u]=f,v=u;
		}
	}sc(f);
    return 0;
}