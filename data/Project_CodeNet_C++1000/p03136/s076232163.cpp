#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef long long ll;
typedef int I;
int main() {
    lli n;
    cin>>n;
    lli a[n],i,sum=0;
    for(i=0;i<n;i++)
     cin>>a[i];
     sort(a,a+n);
     for(i=0;i<n-1;i++)
     sum=sum+a[i];
     if(sum>a[n-1])
     cout<<"Yes"<<"\n";
     else
     cout<<"No"<<"\n";
}
  