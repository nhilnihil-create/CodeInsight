#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin>>n;

    int ans=0;

    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        int cnt=0;
        while(a%2==0)
        {
            cnt++;
            a/=2;
        }
        ans+=cnt;
    }

    cout<<ans<<"\n";

    return 0;
}
