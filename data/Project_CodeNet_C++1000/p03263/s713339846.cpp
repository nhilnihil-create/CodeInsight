
#include<bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

#define            ll              long long
#define            pb              push_back
#define            mp              make_pair
#define            loop(i,a,n)     for(int i=a;i<=n;++i)
#define            clr(x)          memset(x,0,sizeof x)
#define            min3(a,b,c)     min(a,min(b,c))
#define            max3(a,b,c)     max(a,max(b,c))
#define            min4(a,b,c,d)   min(a,min(b,min(c,d)))
#define            max4(a,b,c,d)   max(a,max(b,max(c,d)))
#define            fast            ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define            pii             pair<int,int>
#define            pll             pair<ll,ll>
#define            pli             pair<ll,int>
#define            pil             pair<int,ll>
#define            FF              first
#define            SS              second
#define            PI              acos(-1.0)
#define            bug             cout<<"ok"<<endl;

using namespace std;
using namespace __gnu_pbds;

typedef tree<int , null_type,less<int>,
       rb_tree_tag, tree_order_statistics_node_update> anik;

const int MOD = 1e9 + 7;
const ll MX= 1e9;
const ll INF = 1e9;

const ll N=520;
ll a[N][N],ans[N*N][4];

main()
{
   ll n,m;
   cin>>n>>m;

   for(int i=1;i<=n;++i)
   {
       for(int j=1;j<=m;++j)
        cin>>a[i][j];
   }
   int cnt=0,k=0;


   for(int i=1;i<=n;++i)
   {
       for(int j=1;j<m;++j)
       {
           if(a[i][j]%2==1)
           {
                   a[i][j+1]+=1;
                   ans[k][0]=i;
                   ans[k][1]=j;
                   ans[k][2]=i;
                   ans[k++][3]=j+1;

           }

       }
   }
   for(int i=1;i<n;++i)
   {
       if(a[i][m]%2==1)
       {
           a[i+1][m]+=1;
           ans[k][0]=i;
           ans[k][1]=m;
           ans[k][2]=i+1;
           ans[k++][3]=m;
       }
   }

   cout<<k<<endl;
   for(int i=0;i<k;++i)
    cout<<ans[i][0]<<" "<<ans[i][1]<<" "<<ans[i][2]<<" "<<ans[i][3]<<endl;
}

