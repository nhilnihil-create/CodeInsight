#include<cstdio>
#include<cstdlib>
using namespace std;
const int maxn=200010;
char a[maxn],b[maxn];

int ca[4],cb[4],n,m,N,sx,sy;
int main(){
    scanf("%d%d",&n,&m);
    scanf("%d%d%d%s%s",&N,&sx,&sy,a+1,b+1);
    //puts(a+1);
    //puts(b+1);
    /*for(int i=1,x,y;i<=N;++i){
        if(a[i]=='L')++ca[0];
        else if(a[i]=='R')++ca[1];
        else if(a[i]=='U')++ca[2];
        else ++ca[3];
        if(sy+ca[1]-cb[0]>m){ans=1;break;}
        if(sy+cb[1]-ca[0]<=0){ans=1;break;}
        if(sx+ca[2]-cb[3]>n){ans=1;break;}
        if(sx+cb[2]-ca[3]<=0){ans=1;break;}
        if(b[i]=='L')++cb[0];
        else if(b[i]=='R')++cb[1];
        else if(b[i]=='U')++cb[2];
        else ++cb[3];
        if(sy+ca[1]-cb[0]>m){ans=1;break;}
        if(sy+cb[1]-ca[0]<=0){ans=1;break;}
        if(sx+ca[2]-cb[3]>n){ans=1;break;}
        if(sx+cb[2]-ca[3]<=0){ans=1;break;}
    }*/
    for(int i=1,y=sy;i<=N;++i){
        if(a[i]=='L')--y;
        if(y<=0)goto A;
        if(b[i]=='R'&&y<m)++y;
    }
    for(int i=1,y=sy;i<=N;++i){
        if(a[i]=='R')++y;
        if(y>m)goto A;
        if(b[i]=='L'&&y>1)--y;
    }
    for(int i=1,x=sx;i<=N;++i){
        if(a[i]=='D')++x;
        if(x>n)goto A;
        if(b[i]=='U'&&x>1)--x;
    }
    for(int i=1,x=sx;i<=N;++i){
        if(a[i]=='U')--x;
        if(x<=0)goto A;
        if(b[i]=='D'&&x<n)++x;
    }
    goto B;
    A:puts("NO");
    exit(0);
    B:puts("YES");
    return 0;
}