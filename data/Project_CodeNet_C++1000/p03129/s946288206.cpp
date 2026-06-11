#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    set<int>p;
    for(int i=1;i<=n;i+=2)
    {
        p.insert(i);
    }
    int x=p.size();
   int w=n-x;
   int v=max(x,w);
   if(v>=k)
   {
       cout<<"YES"<<endl;
   }
   else
   {
       cout<<"NO"<<endl;
   }
    return 0;
}
