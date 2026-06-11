#include<bits/stdc++.h>
using namespace std;

#define int long long int 

int32_t main()
{
   int n,m,k;
   cin>>n>>m>>k;
   set<int> s;
   for(int i=0;i<k;i++)
   {
      
      s.insert(n);
      s.insert(m);
      m--;
      n++;
      if(n>m)
      break;
   }  
   for(auto i:s)
   cout<<i<<endl;
}