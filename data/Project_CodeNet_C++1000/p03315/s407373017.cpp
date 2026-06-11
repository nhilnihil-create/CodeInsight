#include <bits/stdc++.h>
using namespace std;
#define int long long int
int32_t main()
{
    string s;
    cin>>s;
    int ans=0;
    for(auto &it:s)
    {
        if(it=='+')
        ans++;
        else
        ans--;
    }
    cout<<ans<<endl;
    return 0;
}