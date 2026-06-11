#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const int INF = 1001001001;
const int MOD = 1000000007;

template <typename T>
void print(const T &v);

int main()
{
    string s;
    int k;
    cin >> s >> k;
    map<string, int> mp;
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= min(n - i, 5); j++)
        {
            string sub = s.substr(i, j);
            mp[sub]++;
        }
    }
    int cnt = 1;
    for (auto m : mp)
    {
        if (cnt == k)
        {
            cout << m.first << endl;
            return 0;
        }
        cnt++;
    }
}

// Use For Debug
template <typename T>
void print(T const &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (i)
            cout << " ";
        cout << v[i];
    }
    cout << endl;
}
