#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll mod = 1e9 + 7;

int main(void)
{
    int n;
    string s;
    cin >> n >> s;

    vector<ll> histo(26, 0);
    for (int i = 0; i < n; i++)
    {
        histo[s[i] - 97]++;
    }

    ll result = 1;
    for (int i = 0; i < 26; i++)
    {
        result *= ((histo[i] + 1) % mod);
        result %= mod;
    }
    
    cout << (result - 1) % mod<< endl;
    
    return 0;
}
