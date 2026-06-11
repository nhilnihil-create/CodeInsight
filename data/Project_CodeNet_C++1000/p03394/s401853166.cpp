#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define SF scanf
#define PF printf
#define MAXN 100010
using namespace std;
int n;
bool used[MAXN];
int main(){
    SF("%d",&n);
    if(n==3){
        PF("2 5 63");
        return 0;
    }
    used[2]=1,used[4]=1,used[3]=1,used[9]=1;
    n-=4;
    int x=8,y=10;
    while(n>1&&y<=30000){
        used[x]=1;
        used[y]=1;
        n-=2;
        x+=6;
        y+=6;
    }
    x=15,y=21;
    while(n>1&&y<=30000){
        used[x]=1;
        used[y]=1;
        n-=2;
        x+=12;
        y+=12;
    }
    x=6;
    while(n>0&&x<=30000){
        used[x]=1;
        x+=6;
        n--;
    }
    for(int i=2;i<=30000;i++)
        if(used[i]==1)
            PF("%d ",i);
} 