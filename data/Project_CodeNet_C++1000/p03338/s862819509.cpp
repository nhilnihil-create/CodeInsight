#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define P 1000000007
#define inf 1e18
int main()
{

    ll i, j;
    string s;
    ll n;
    cin >> n;
    cin >> s;
    ll ans = 0;
    map<char, ll> m1, m2;
    for (i = 1; i < n - 1; i++)
    {
        string t1 = s.substr(0, i);
        string t2 = s.substr(i, n - i);
               
        for (j = 0; j < t1.length(); j++)
        {
            m1[t1[j]]++;
        }
        for (j = 0; j < t2.length(); j++)
        {
            m2[t2[j]]++;
        }
        ll count = 0;
        for (char c = 'a'; c <= 'z'; c++)
        {    //cout<<m1[c]<<" "<<m2[c]<<"\n";
             if(m1[c] * m2[c] != 0)
               count++;
        } 
        ans = max(ans,count);

        m1.clear();
        m2.clear();
    }
    cout << ans << "\n";

    return (0);
}