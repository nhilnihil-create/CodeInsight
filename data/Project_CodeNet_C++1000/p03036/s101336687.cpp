#include<bits/stdc++.h>
using namespace std;
#define nl cout<<'\n';
int main()
{
    int r,d,x;
    cin>>r>>d>>x;
    int s=r*x-d;
    cout<<s;
    nl;
    for(int i=2;i<=10;i++)
    {
      s= r*s-d;
      cout<<s;
      nl;
    }
    return 0;
}
