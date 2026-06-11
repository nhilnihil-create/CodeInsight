#include <bits/stdc++.h>
#define rep(i, n) for (long long int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
template <class T>

inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}
const long long INF = 1LL << 60;
int cnt = 0;
int main()
{
    string s, t;
    cin >> s >> t;
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    reverse(t.begin(), t.end());
    if (s < t)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}
