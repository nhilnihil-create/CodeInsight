#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    string s;
    cin >> s;
    
    ll K;
    cin >> K;

    map<string,ll> mp;

    for(ll i = 0; i < s.size(); i++)
    {
        for(ll j = 1; j <= K; j++)
        {
            string tmp;
            for(ll k = 0; k < j; k++)
            {
                if(i+k >= s.size())break;
                tmp.push_back(s[i+k]);
            }
            mp[tmp]++;
        }
    }
    
    ll count = 0;
    for(auto e:mp)
    {
        count++;
        if(count == K)
        {
            cout << e.first << endl;
            return 0;
        }
    }
}