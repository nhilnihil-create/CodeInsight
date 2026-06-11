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
    string ss;
    cin >> ss;
    ss.push_back('Z'); // ダミー
    string s;
    for (int i = 0; i < ss.size(); i++)
    {
        if (ss[i] == 'A')
        {
            s.push_back('A');
        }
        else if (ss[i] == 'B' && ss[i + 1] == 'C')
        {
            s.push_back('B');
            i++;
        }
        else
        {
            s.push_back('C');
        }
    }
    int n = s.size();
    int a_cnt = 0;
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'A')
        {
            ++a_cnt;
        }
        else if (s[i] == 'B')
        {
            ans += a_cnt;
        }
        else
        {
            a_cnt = 0;
        }
    }
    cout << ans << endl;
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