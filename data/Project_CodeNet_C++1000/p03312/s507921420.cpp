#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int const maxn=2e5+5;
ll const INF=1e18;
ll tmp,b[maxn],res;
int n;
inline ll read(){
   ll s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
ll get(int l,int pos,int r){
    res=min(res,max(max(b[l],b[pos]-b[l]),max(b[r]-b[pos],b[n]-b[r]))-min(min(b[l],b[pos]-b[l]),min(b[r]-b[pos],b[n]-b[r])));
}
void dfs(int pos){
    int l=lower_bound(b+1,b+n+1,b[pos]>>1)-(b+1);
    int r=lower_bound(b+1,b+n+1,b[pos]+((b[n]-b[pos])>>1))-(b+1);
    get(l,pos,r);
    if(l+1<pos) get(l+1,pos,r);
    if(r+1<n) get(l,pos,r+1);
    if(l+1<pos&&r+1<n) get(l+1,pos,r+1);
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        tmp=read();
        b[i]=b[i-1]+tmp;
    }
    res=INF;
    for(int i=2;i<=n-2;i++) dfs(i);
    printf("%lld\n",res);
}
