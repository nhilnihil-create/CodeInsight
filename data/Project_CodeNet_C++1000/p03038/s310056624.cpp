#include<bits/stdc++.h>
using namespace std;
typedef     long long    ll;
typedef     vector<int> vi;
typedef     vector<long long> vl;
typedef     pair<int, int>pi;
typedef     pair<long long, long long>pl;
#define F   first
#define S   second
#define pb  push_back
#define     all(x)      x.begin() , x.end()
#define mp  make_pair
#define       FOR(i,a,b) for(i=a;i<=b;i++)
#define     mem(a)      memset(a , 0 ,sizeof a)
#define     memn(a)     memset(a , -1 ,sizeof a)
int main()
{
  int t;
  t=1;
  //cin >> t;
  while (t--)
  {
    ll n,i,j,x,y,m,s=0;
    cin>>n>>m;
    int a[n+3];
    pair<int,int>p[m+1];
    for(i=1;i<=n;i++) cin>>a[i];
      sort(a+1,a+n+1);
    for(i=0;i<m;i++)
    {
      cin>>x>>y;
      p[i].first=y;
      p[i].second=x;
    }
    sort(p,p+m);
    x=1;
    for(i=m-1;i>=0;i--)
    {
     int  l=x;
      if(p[i].first>a[x]){
      for(j=l;j<=l+p[i].second-1&&j<=n;j++)
      {
        if(a[j]<p[i].first)
        {
          a[j]=p[i].first;
        }else
        {
          break;
        }
        x++;

      }
    
     }
    }
    // int l=1;
    // for(i=m-1;i>=0;i--)
    //  {
    //    x=p[i].second;
    //    if(p[i].fisrt>a[l])
    //    {
    //     for(j=l+1;j<=l+x-1&&j<=l+n-1;j++)
    //     {
    //         if()
    //     }
    //    }
    //  }
   for(i=1;i<=n;i++)
   {
    s+=a[i];
  // cout<<a[i]<<" ";
   }
   cout<<s<<endl;

  }
  return 0;
}