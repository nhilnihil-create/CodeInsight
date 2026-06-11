#include<bits/stdc++.h>
using namespace std;
const int M=2e3+5;
int que[M],order[M],tmp[M],now[M],tot,top,n,k,q;
void in()
{
    scanf("%d%d%d",&n,&k,&q);
    for(int i=1;i<=n;++i)scanf("%d",&que[i]),order[i]=que[i];
}
void add(int le,int ri)
{
    tot=0;
    if(le>ri||ri-le+1<k)return;
    for(int i=le;i<=ri;++i)tmp[++tot]=que[i];
    sort(tmp+1,tmp+1+tot);
    for(int i=ri-le+2-k;i>=1;--i)now[++top]=tmp[i];
}
int test(int mn)
{
    int p=1;top=0;
    for(int i=1;i<=n;++i)if(que[i]<mn)add(p,i-1),p=i+1;
    if(top<q)return INT_MAX; 
    sort(now+1,now+1+top);
    return now[q]-mn;
}
void ac()
{
    int ans=INT_MAX;
    sort(order+1,order+1+n);que[++n]=-INT_MAX;
    for(int i=1;i<n;++i)ans=min(test(order[i]),ans);
    printf("%d",ans);
}
int main()
{
    in();ac();
    return 0;
}