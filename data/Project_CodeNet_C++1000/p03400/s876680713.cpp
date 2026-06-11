#include<bits/stdc++.h>

using namespace std;

int main()
{
   int n,d,x,a[101],i,j,sum=0;
   cin>>n>>d>>x;
   for(i=0;i<n;i++){
    cin>>a[i];
   }
   for(i=0;i<n;i++){
    for(j=1;j<=d;j++){
        if((j*a[i]+1)<=d) sum+=1;
        else break;
    }
   }
   cout<<n+sum+x;
    return 0;
}
