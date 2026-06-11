/***********************************************************
 *This code By @1353055672(Ligen)                          *
 *[Warning]You're not excepted to understand this code!    *
 *RP++                                                     *
 ***********************************************************/
//#pragma GCC optimize(3)
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
#include<map>
#define ll long long
#define ull unsigned long long
#define mn 1000020
#define inf (ll)(1e18)
#define mod (int)(1e9+7)
#define FOR(a,b,c) for (register ll a=b;a<=c;a++)
#define FORD(a,b,c) for (register ll a=b;a>=c;a--)
using namespace std;
inline ll read(){
    ll x=0,f=1;
    char c=getchar();
    while (c<'0'||c>'9'){
        if (c=='-')f=-1;
        c=getchar();
    }
    while (c>='0'&&c<='9'){
        x=x*10+c-'0';
        c=getchar();
    }
    return x*f;
}
inline void writeln(ll a){
    if(a==0){puts("0");return;}
    if(a<0)putchar('-'),a=-a;
    char c1[120];
    int h=0;
    while(a)c1[++h]=a%10+'0',a/=10;
    FORD(i,h,1)putchar(c1[i]);putchar('\n');
    return;
}
inline ll Max(ll a,ll b){return (a>b)?a:b;}
inline ll Min(ll a,ll b){return (a<b)?a:b;}
inline ll Abs(ll x){return (x<0)?-x:x;}
inline void Swap(ll &x,ll &y){ll t=x;x=y;y=t;}
inline ll gcd(ll a,ll b){return a==0?b:gcd(b%a,a);}
//---------------------Head Files--------------------------//
int v[100020],a[520][100020];
int main(){
	ll n=read();
	if(1ll*floor(sqrt(1ll*8*n+1))*floor(sqrt(1ll*8*n+1))!=1ll*8*n+1)return puts("No"),0;
	ll k=(sqrt(8*n+1)+1)/2,num=0,bl=2ll*n/k,mx=0;
	puts("Yes");printf("%d\n",k);
	FOR(i,1,k){
//		printf("%d ",);
		num=0;
		FOR(j,1,i-1){
			FOR(kk,1,bl)if(v[a[j][kk]]<2){
				v[a[j][kk]]++;a[i][++num]=a[j][kk];break;
			}
			if(num>bl)break;
		}
		if(num<bl){FOR(j,num+1,bl)a[i][j]=++mx,v[mx]++;num=bl;}
		printf("%d ",num);
		FOR(j,1,num-1)printf("%d ",a[i][j]);printf("%d\n",a[i][num]);
	}
	return 0;
}
