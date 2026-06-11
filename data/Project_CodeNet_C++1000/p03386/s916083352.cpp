#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int a,b,k;
    cin>>a>>b>>k;

    for(int i=a;i<=b;i++)
    {
        if(i<a+k||b-k<i)cout<<i<<"\n";
    }

    return 0;
}
