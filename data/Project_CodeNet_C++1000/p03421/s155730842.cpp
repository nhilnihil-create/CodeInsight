#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a,b;
  std::ios::sync_with_stdio(false);
   cin>>n>>a>>b;
   if(a+b>n+1||(long long)a*b<n)
   {
       puts("-1");

   }
   else
   {
       while(n)
       {
           int mi=min(a,n-(b-1));
           for(int i=n-mi+1;i<=n;i++)
            cout<<i<<' ';
            n-=mi;
            b--;
       }
   }

    return 0;
}
