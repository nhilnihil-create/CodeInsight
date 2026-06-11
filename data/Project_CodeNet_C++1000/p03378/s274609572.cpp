#include <bits/stdc++.h>
using namespace std;
int pre[104];
int main()
{
       int n,m,x,s1=0,s2=0;
       cin>>n>>m>>x;
      int arr[n+4];
      for(int i=0;i<m;i++)
      {
          cin>>arr[i];
          pre[arr[i]]=1;
      }

      for(int i=0;i<=x;i++){
      s1+=pre[i];
      }
      for(int i=x;i<=n;i++){
      s2+=pre[i];
      }
      if(s1<s2)
        cout<<s1;
      else cout<<s2;
    return 0;
   }