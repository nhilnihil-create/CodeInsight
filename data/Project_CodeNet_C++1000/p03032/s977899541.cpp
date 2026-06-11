#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
#define int ll
int ans=0;
int32_t main()
{
  #ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
    freopen("out","w",stdout);
    #endif
  int n,k;
  cin>>n>>k;
  vector<int> a(n);
  for(int &i:a)cin>>i;

  for(int A=0;A<=min(n,k);A++)
    for(int B=0;B<=min(n,k);B++)
    {
      if(A+B>min(n,k))continue;
      int tmp=0;
      multiset<int> s;
      for(int i=0;i<A;i++){tmp+=a[i];s.insert(a[i]);}
      for(int i=0;i<B;i++){tmp+=a[n-1-i];s.insert(a[n-1-i]);}

      for(int i=0;i<k-(A+B);i++)
      {
        if(s.empty())break;
        int p=*s.begin();
        if(p<0){tmp-=p;s.erase(s.find(p));}
        else break;
      }
      ans=max(ans,tmp);

    }

  
 cout<<ans;
 

}