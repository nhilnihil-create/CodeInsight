#include<bits/stdc++.h>
using namespace std;
int n,x,r,m;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++,r+=x,m=max(m,x))cin>>x;
    r-=m;r+=m/2;
    cout<<r<<endl;
    return 0;
}