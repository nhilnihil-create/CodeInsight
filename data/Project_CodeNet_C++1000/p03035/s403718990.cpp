#include<bits/stdc++.h>
using namespace std;
#define nl cout<<'\n';
int main()
{
    int p,q;
    cin>>p>>q;
    if(p>=0&&p<=5)
      cout<<0;
    else if(p>=6&&p<=12)
      cout<<q/2;
    else
      cout<<q;
    nl;
    return 0;
}
