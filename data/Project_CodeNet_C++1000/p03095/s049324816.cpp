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
    int N;
    string S;
    cin >> N >> S;
    vector<int> alp(26, 0);
    for (char c : S)
    {
        alp[c - 'a']++;
    }
    ll ans = 1;
    for (int a : alp)
    {
        ans = (ans * (a + 1)) % MOD;
    }
    if (ans != 0)
    {
        cout << ans - 1 << endl;
    }
    else
    {
        cout << MOD - 1 << endl;
    }
    return 0;
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
