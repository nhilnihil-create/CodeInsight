#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n,m;
    cin>>n>>m;

    int l=1,r=n;

    for(int i=0;i<m;i++)
    {
        int il,ir;
        cin>>il>>ir;

        l=max(l,il);
        r=min(r,ir);
    }

    cout<<max(0,r-l+1)<<"\n";

    return 0;
}
