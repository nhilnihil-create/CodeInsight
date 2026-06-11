#include<bits/stdc++.h>
using namespace std;
#define lli                      int long long
#define ull                      unsigned long long
#define ld                       long double
#define pi                       acos(-1)
#define pb                       push_back
#define pbk                      pop_back
#define mp                       make_pair
#define all(v)                   v.begin(),v.end()
#define ff                       first
#define ss                       second
#define pii                      pair<int,int>
#define gcd(a,b)                 __gcd(a,b)
#define lcm(a,b)                (a/gcd(a,b))*b
#define READ                     freopen("in.txt","r",stdin);
#define WRITE                    freopen("outer.txt","w",stdout);
#define sortv(t)                  sort(t.begin(),t.end())
#define mem(a,b)                 memset(a,b,sizeof a)
#define t_c(t)                          for(int z=1;z<=t;z++)
#define p_c                             printf("Case %d: ",z)
#define LINE_PRINT_CASE          printf("Case %d:\n",z)
#define sf                       scanf
#define pf                       printf
#define dist(ax,ay,bx,by)        sqrt((ax-bx)*(ax-bx)+(ay-by)*(ay-by))
#define MX                       100005
#define inf                      10000000000000000+7
#define M                        1000000002
#define MINI                     -1000000003
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move

//int kx[]={+2,+2,-2,-2,+1,+1,-1,-1};     //Knights move
//int ky[]={+1,-1,+1,-1,+2,-2,+2,-2};     //Knights move


//#define for(i,a,n)    for(int i=a;i<n;i++)
//it=myset.find(20);
//int a[8]= {0,0,-1,1,-1,1,-1,1};
//int b[8]= {-1,1,0,0,-1,1,1  ,-1};


int a[105],ans=0;
vector<int>v;

void func(int l,int r)
{
    int minn=M,p=0;

    int t=l;
   for(int i=l;i<=r;i++)
   {
       if(a[i]==0)p++;
       minn=min(a[i],minn);
   }ans+=minn;
   if(p==(r-l+1)) return;
   for(int i=l;i<=r;i++)
   {
       a[i]=a[i]-minn;
       if(a[i]==0)
       {
           if((i-1)>=t)
       {
           func(t,i-1);
       }t=i+1;
       }
   }
   if(t<=r) func(t,r);

   return ;
}

int main()
{
   int n,i,j;
   cin>>n;
   map<int,int>mm;

   for(i=0;i<n;i++){cin>>a[i];
   }
   func(0,n-1);
   cout<<ans<<endl;
    return 0;
}
