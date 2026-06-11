#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
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

int main()
{
    char b[2];
    cin >> b;
    if (strcmp(b, "A") == 0)
        cout << 'T' << endl;
    else if (strcmp(b, "T") == 0)
        cout << 'A' << endl;
    else if (strcmp(b, "C") == 0)
        cout << 'G' << endl;
    else if (strcmp(b, "G") == 0)
        cout << 'C' << endl;
    return 0;
}
