#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define vi vector<int>
#define nl endl
#define tc    \
    ll t;     \
    cin >> t; \
    while (t--)
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL);
using namespace std;
int main()
{
    fastio;
    string s;
    cin >> s;
    int n = s.size(), c = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] == '1' && s[i + 1] == '1')
        {
            c++;
            s[i + 1] = '0';
        }
        else if (s[i] == '0' && s[i + 1] == '0')
        {
            c++;
            s[i + 1] = '1';
        }
    }
    cout<<c;
}