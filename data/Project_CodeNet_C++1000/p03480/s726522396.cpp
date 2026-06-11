#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
const int inf = (1 << 30) - 1;
const ll infll = (1LL << 61) - 1;

string s;

int main()
{
    cin >> s;
    int ans, N = s.size();
    ans = N;
    for (int i = 0; i + 1 < N; i++)
    {
        if (s[i] != s[i + 1])
        {
            ans = min(max(N - i - 1, i + 1), ans);
        }
    }

    cout << ans << endl;
}