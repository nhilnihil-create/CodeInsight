#include<bits/stdc++.h>
using namespace std;

#define int long long int 

int32_t main()
{
    int a,b,c;
    cin>>a>>b>>c;
    cout<<max({a,b,c})*10+a+b+c-max({a,b,c})<<endl;
}