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
    string S, T;
    cin >> S >> T;
    int n = S.size();
    vector<pair<char, char>> pr(n);
    vector<bool> seen(26, false);
    for (int i = 0; i < n; i++)
    {
        pr[i].first = S[i];
        pr[i].second = T[i];
    }
    sort(pr.begin(), pr.end());
    char before = '0';
    for (int i = 0; i < n; i++)
    {
        if (pr[i].first == before)
        {
            if (pr[i].second != pr[i - 1].second)
            {
                No
            }
            continue;
        }
        if (seen[pr[i].second - 'a'])
        {
            No
        }
        seen[pr[i].second - 'a'] = true;
        before = pr[i].first;
    }
    Yes
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
