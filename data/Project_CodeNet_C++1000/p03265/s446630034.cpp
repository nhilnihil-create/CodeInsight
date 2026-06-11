#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int x = c-a;
    int y = d-b;
    cout<<c-y<<' '<<d+x<<' '<<a-y<<' '<<b+x;
    return 0;
}
