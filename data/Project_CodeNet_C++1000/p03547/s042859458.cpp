#include<bits/stdc++.h>
using namespace std;
#define nl cout<<'\n';
int main()
{
    char a,b;
    cin>>a>>b;
    if(a>b)
      cout<<'>';
    else if(a==b)
      cout<<'=';
    else
      cout<<'<';
    nl;
    return 0;
}
