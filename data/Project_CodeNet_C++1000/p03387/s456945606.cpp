#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    vector<int> a(3);
    for(int i=0;i<3;i++)cin>>a[i];

    sort(a.begin(),a.end(),greater<int>());

    int ans=0;
    ans+=a[0]-a[1];
    ans+=(a[1]-a[2])/2;
    ans+=((a[1]-a[2])%2)*2;

    cout<<ans<<"\n";

    return 0;
}
