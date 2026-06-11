#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

int main()
{
    long long int a,b,c,d;
    cin>>a>>b>>c>>d;
    a+=b;
    c+=d;
    if(a>c)cout<<"Left";
    else if(c>a)cout<<"Right";
    else cout<<"Balanced";

    return 0;
}
