#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    if(c<a+b||c==a+b)
      cout<<"Yes";
    else
      cout<<"No";
    return 0;
}