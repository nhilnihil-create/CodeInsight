#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n,a,t,i,j,k;
    cin>>n>>a;
    i=(n*2)-1;
    j=(a*2)-1;
    i=max(i,j);
    k=n+a;
    k=max(i,k);
    cout<<k<<endl;
      return 0;
}
