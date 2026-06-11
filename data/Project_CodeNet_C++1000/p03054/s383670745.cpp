/*Unknown_Ghost*/
/*AGC033B LRUD Game*/
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<vector>
using namespace std;

#define LL long long
#define MAXN 200000
#define MOD 998244353
#define Pr pair<int,int>
#define X first
#define Y second
#define mem(x,p) memset(x,p,sizeof(x))

LL read(){
  LL x=0,F=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')F=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}
  return x*F;
}
int add(int x,int y){return (x+y>=MOD)?x+y-MOD:x+y;}
int dec(int x,int y){return (x-y<0)?x-y+MOD:x-y;}
int mul(int x,int y){return 1LL*x*y%MOD;}

int h,w,n,sx,sy;
char S[MAXN+5],T[MAXN+5];
char dir[]={'L','R','U','D'};
int px[]={0,0,-1,1},py[]={-1,1,0,0};
int main()
{
    h=read(),w=read(),n=read();
    sx=read(),sy=read();
    scanf("%s %s",S+1,T+1);
    for(int k=0;k<4;k++){
        int nx=sx,ny=sy;
        for(int i=1;i<=n;i++){
            if(S[i]==dir[k])nx+=px[k],ny+=py[k];
            if(!(nx>=1&&ny>=1&&nx<=h&&ny<=w)){printf("NO\n");return 0;}
            if(T[i]==dir[k^1])nx+=px[k^1],ny+=py[k^1];
            nx=min(h,max(1,nx)),ny=min(w,max(1,ny));
        }
    }
    printf("YES\n");
}
