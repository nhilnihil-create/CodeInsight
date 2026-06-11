#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b)      for(int i=a;i<=b;i++)
#define revp(i,b,a)     for(int i=b;i>=a;i--)

int a,b,c,d;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>a>>b>>c>>d;
    int x=c-a,y=d-b;
    cout<<c-y<<" "<<d+x<<" "<<a-y<<" "<<b+x;
}

