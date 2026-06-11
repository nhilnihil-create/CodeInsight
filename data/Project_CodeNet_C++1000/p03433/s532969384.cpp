#include<bits/stdc++.h>
using namespace std;
#define nl cout<<'\n';
int main()
{
    long long x,a;
    cin>>x>>a;
    x=x%500;
    if(x<=a)
      cout<<"Yes";
    else
      cout<<"No";
    nl;
    return 0;
}
