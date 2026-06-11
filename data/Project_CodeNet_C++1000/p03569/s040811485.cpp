#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1001001001;
const ll LINF = 1LL << 60;
const int MOD = 1'000'000'007;

template <typename T>
void print(const T &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (i)
            cout << ' ';
        cout << v[i];
    }
    cout << endl;
}

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

// const int MAX = 1010;

int main()
{
    string s;
    cin >> s;
    int left = 0;
    int right = s.size() - 1;
    int cnt = 0;
    while (left != right)
    {
        // cout << "left:" << left << ' ';
        // cout << "right:" << right << endl;
        if (s[left] == s[right])
        {
            if (right - left == 1)
            {
                break;
            }
            ++left;
            --right;
            continue;
        }
        else if (s[left] == 'x')
        {
            ++cnt;
            ++left;
        }
        else if (s[right] == 'x')
        {
            ++cnt;
            --right;
        }
        else
        {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << cnt << endl;
    return 0;
}