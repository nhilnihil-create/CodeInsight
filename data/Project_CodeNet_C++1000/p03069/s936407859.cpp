#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1001001001;
const ll LINF = 1001001001001001;
const int MOD = 1000000007;

template <typename T>
void print(const T &v);

int main()
{
    int n;
    string s;
    cin >> n >> s;
    // 境界線より右の白と，境界線より左の黒をカウントする
    int black = 0, white = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '.')
        {
            ++white;
        }
    }
    // cout << black << ':' << white << endl;
    int mini = black + white;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '.')
        {
            --white;
        }
        else
        {
            ++black;
        }
        // cout << black << ':' << white << endl;
        mini = min(mini, black + white);
    }
    cout << mini << endl;
    return 0;
}

// Use For Debug
template <typename T>
void print(T const &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (i)
            cout << ' ';
        cout << v[i];
    }
    cout << endl;
}