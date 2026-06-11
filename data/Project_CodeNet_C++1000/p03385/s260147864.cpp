#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define Yes                \
    cout << "Yes" << endl; \
    return 0;
#define No                \
    cout << "No" << endl; \
    return 0;
using namespace std;
using ll = long long;
const int INF = 1001001001;
const int MOD = 1000000007;
typedef long long ll;

template <typename T>
void print(const T &v);

int main()
{
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    if (s == "abc")
    {
        Yes
    }
    else
    {
        No
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
