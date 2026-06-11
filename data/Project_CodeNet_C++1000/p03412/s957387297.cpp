#include<bits/stdc++.h>
#define ll long long
#define lowbit(x) x&-x
using namespace std;
int read(){
    char c;int s=0,t=1;
    while(!isdigit(c=getchar()))if(c=='-')t=-1;
    do{s=s*10+c-'0';}while(isdigit(c=getchar()));
    return s*t;
}
int min(int a,int b){return a<b?a:b;}
int max(int a,int b){return a<b?b:a;}
int ab(int x){return x>0?x:-x;}
const int inf=0x3f3f3f3f,maxn=200010;

int n,A[maxn],B[maxn],cx[40][maxn],dx[maxn],ans=0;

int main(){
    n=read();
    for(int i=1;i<=n;i++)A[i]=read();
    for(int i=1;i<=n;i++)B[i]=read();
    for(int k=0;k<28;k++){
        if(!k)for(int i=1;i<=n;i++)cx[k][i]=((1<<k)&B[i]);else
        for(int i=1;i<=n;i++)cx[k][i]=cx[k-1][i]^((1<<k)&B[i]);
    }
    for(int k=0;k<28;k++)sort(cx[k]+1,cx[k]+n+1);
    for(int k=1;k<=28;k++){
        for(int i=1;i<=n;i++){
            dx[i]^=(1<<(k-1))&A[i];
            int x=lower_bound(cx[k-1]+1,cx[k-1]+n+1,((1<<k)-dx[i]))-cx[k-1];
            ans^=(((n-x+1)%2)<<k);
        }
    }
    int a,b,c,d;
    for(int k=0;k<=28;k++){
        a=b=c=d=0;
        for(int i=1;i<=n;i++)if((1<<k)&A[i])b++;else a++;
        for(int i=1;i<=n;i++)if((1<<k)&B[i])d++;else c++;
        ans^=(((1ll*a*d%2+1ll*b*c%2)%2)<<k);
    }
    printf("%d",ans);
    return 0;
}