#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef long long ll;
typedef int I;
int main() {
    lli n,m,sum=0,i;
    cin>>n>>m;
   vector<int>a(m);
   if(n>=m)
   cout<<0<<"\n";
   else{
    for(i=0;i<m;i++)
     cin>>a[i];
     sort(a.begin(),a.end());
     vector<int>v(m-1);
     for(i=0;i<m-1;i++)
       v[i]=a[i+1]-a[i];
    sort(v.begin(),v.end());
    for(i=0;i<m-n;i++)
    sum=sum+v[i];
    cout<<sum<<"\n";
   }
}
  