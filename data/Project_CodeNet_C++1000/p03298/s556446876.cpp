#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

typedef long long ll;

ll n, ans;
string s;
map<pair<string, string>, ll> ma;

int main()
{
    cin>>n>>s;
    for(ll i = 0; i < (1 << n); i++)
    {
        string s1, s2;
        s1 = s2 = "";
        for(ll j = 0; j < n; j++)
        {
            if(i & (1 << j)) s1.push_back(s[j]);
            else s2.push_back(s[j]);
        }
        ma[make_pair(s1, s2)]++;
    }
    for(ll i = 0; i < (1 << n); i++)
    {
        string s1, s2;
        s1 = s2 = "";
        for(ll j = 0; j < n; j++)
        {
            if(i & (1 << j)) s1.push_back(s[2 * n - j - 1]);
            else s2.push_back(s[2 * n - j - 1]);
        }
        ans += ma[make_pair(s1, s2)];
    }
    cout<<ans<<endl;
    return 0;
}
