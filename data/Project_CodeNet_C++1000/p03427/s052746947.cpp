#include <bits/stdc++.h>
using namespace std;

using str = string;
using ss = stringstream;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    str n;
    cin>>n;

    int ans=n[0]-'0'-1;

    bool nine=true;

    for(int i=1;i<n.size();i++)
    {
        if(n[i]!='9')nine=false;
        ans+=9;
    }

    if(nine)ans++;

    cout<<ans<<"\n";

    return 0;
}
