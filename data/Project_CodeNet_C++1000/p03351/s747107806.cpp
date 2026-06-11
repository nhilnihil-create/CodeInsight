#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c,x;
    cin>>a>>b>>c>>x;
    if(abs(a-b)<=x && abs(c-b)<=x || abs(a-c)<=x)
        cout<<"Yes\n";
    else
        cout<<"No\n";

    return 0;
}
