#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    cout<<max({10*a+b+c,a+b*10+c,a+b+10*c})<<endl;


    return 0;
}
