#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,k;
    cin>>a>>b>>k;
    map<int,bool>m;
    for(int i=a;i<a+k&&i<=b;i++)
    {
        cout<<i<<'\n';
        m[i]=true;
    }
    for(int i=b-k+1;i<=b;i++)
    {
        if(!m[i]&&i>=a)
        cout<<i<<'\n';
    }
    return 0;
}


