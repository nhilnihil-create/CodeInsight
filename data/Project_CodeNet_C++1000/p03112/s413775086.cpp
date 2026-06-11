#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf =1e15;
const int maxn=1e5+7;
typedef long long ll;
int T;
int a,b,c,n;
ll la[maxn],lb[maxn],x,ans;
double pi=3.14159265359;
double d,r;
int main()
{
   scanf("%d%d%d",&a,&b,&c);

   for(int i=0;i<a;i++)
     scanf("%lld",&la[i]);
   for(int i=0;i<b;i++)
     scanf("%lld",&lb[i]);
   while(c--)
   {
       scanf("%lld",&x);
       ans=inf;
       int aa=lower_bound(la,la+a,x)-la;


       int bb=lower_bound(lb,lb+b,x)-lb;

       //cout<<bL<<"   "<<bR<<endl;
       if(aa<a&&bb<b)
          ans=min(ans,max(la[aa],lb[bb])-x);
       if(aa&&bb)
           ans=min(ans,x-min(la[aa-1],lb[bb-1]));
       if(aa&&bb<b)
           ans=min(ans,max(x-la[aa-1],lb[bb]-x)+2*min(x-la[aa-1],lb[bb]-x));
       if(aa<a&&bb)
           ans=min(ans,max(x-lb[bb-1],la[aa]-x)+2*min(x-lb[bb-1],la[aa]-x));
       printf("%lld\n",ans);
   }
}