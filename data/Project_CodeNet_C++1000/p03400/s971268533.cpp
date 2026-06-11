#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n,d,x;

    cin>>n>>d>>x;

    int ans=x;

    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;

        ans+=1+(d-1)/a;
    }

    cout<<ans<<"\n";

    return 0;
}
