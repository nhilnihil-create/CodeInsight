#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const ll MOD = 1e9 + 7;
const long long INF = 1LL << 60;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    s += "A";

    if (n == 1)
    {
        cout << 1 << endl;
        return 0;
    }

    map<char, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[s.at(i)]++;
    }

    ll answer = 1;
    for (auto itr = mp.begin(); itr != mp.end();itr++)
    {
        int value = itr->second;
        answer = (answer * ((value + 1) % MOD)) % MOD;
    }
    answer--;

    cout << answer << endl;
}