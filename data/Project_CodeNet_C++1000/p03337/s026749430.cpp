#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b;
    cin>>a>>b;
    int x=(a+b),y=(a-b),z=(a*b);
    int m=max({x,y,z});
    cout<<m<<endl;
    return 0;
}
