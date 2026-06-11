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
#define sort(t)                  sort(t.begin(),t.end())
#define mem(a,b)                 memset(a,b,sizeof a)
#define t_c(t)                          for(int z=1;z<=t;z++)
#define p_c                             printf("Case %d: ",z)
#define LINE_PRINT_CASE          printf("Case %d:\n",z)
#define sf                       scanf
#define pf                       printf
#define dist(ax,ay,bx,by)        sqrt((ax-bx)*(ax-bx)+(ay-by)*(ay-by))
#define MX                       10000005
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


int main()
{
    int i,j,n,a;
    cin>>n;
    cin>>a;
    int g=a;
    for(i=1;i<n;i++)
    {
       cin>>a;
       g=gcd(g,a);
    }
    cout<<g<<endl;
    return 0;
}
