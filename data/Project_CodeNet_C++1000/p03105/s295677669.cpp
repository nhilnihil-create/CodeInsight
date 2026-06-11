#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c,i,s=0,minimum=0;
    cin>>a>>b>>c;
    s=b/a;
    minimum=min(s,c);
    cout<<minimum;
    return 0;
}