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
    string s;
    cin >> s;
    cout << "2018/01/" << s[8] << s[9] << endl;
    return 0;
}
