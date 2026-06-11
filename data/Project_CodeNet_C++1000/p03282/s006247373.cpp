#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;
using ss = stringstream;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    str s;
    ll k;
    cin>>s>>k;

    int ans=1;
    int cnt=0;

    for(int i=0;i<s.size();i++)if(s[i]!='1')
    {
        ans=s[i]-'0';
        cnt=i;
        break;
    }

    if(k>cnt)cout<<ans<<"\n";
    else cout<<1<<"\n";

    return 0;
}
