#include <bits/stdc++.h>
using namespace std;

#define INF 100000000

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin>>n;

    int ans=INF;

    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;

        int cnt=0;
        for(;a%2==0;cnt++)a/=2;
        ans=min(ans,cnt);
    }

    cout<<ans<<"\n";

    return 0;
}
