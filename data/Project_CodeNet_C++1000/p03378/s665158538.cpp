#include <bits/stdc++.h>
using namespace std;

int a[110];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n,m,x;
    cin>>n>>m>>x;

    int l=0,r=0;

    for(int i=0;i<m;i++)
    {
        int a;
        cin>>a;
        if(a<x)l++;
        else r++;
    }

    cout<<min(l,r)<<"\n";

    return 0;
}
