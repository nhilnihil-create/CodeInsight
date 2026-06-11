#include <bits/stdc++.h>
using namespace std;

using ll = long long;

using str = string;
using ss = stringstream;

#define MOD 1000000007LL

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;cin>>n;
    str s;cin>>s;

    int cnt=0;
    vector<int> m(26,0);

    ll ans=1;

    for(int i=0;i<n;i++)m[s[i]-'a']++;
    
    for(int i=0;i<26;i++)
    {
        ans*=m[i]+1;
        ans%=MOD;
    }

    ans--;

    cout<<ans<<"\n";

    return 0;
}
