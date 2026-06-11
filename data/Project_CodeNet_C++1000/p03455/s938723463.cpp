#include<bits/stdc++.h>
using namespace std;
#define nl '\n'
int main()
{
    long long a,b;
    cin>>a>>b;
    if((a*b)&1)
      cout<<"Odd";
    else
      cout<<"Even";
    nl;
    return 0;
}