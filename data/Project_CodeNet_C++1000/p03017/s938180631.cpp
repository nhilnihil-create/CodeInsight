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
    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    vector<int> s(n);
    for (int i = 0; i < n; i++)
    {
        char cc;
        cin >> cc;
        if (cc == '.')
        {
            s[i] = 1;
        }
        else
        {
            s[i] = 0;
        }
    }
    // print(s);
    if (a < b && c < d)
    {
        for (int i = a; i < d; i++)
        {
            if (s[i - 1] == 0 && s[i] == 0)
            {
                cout << "No" << endl;
                return 0;
            }
        }
        cout << "Yes" << endl;
        return 0;
    }
    else
    {
        for (int i = a; i < c; i++)
        {
            if (s[i - 1] == 0 && s[i] == 0)
            {
                cout << "No" << endl;
                return 0;
            }
            if (b <= i && i <= d)
            {
                if (s[i - 2] == 1 && s[i - 1] == 1 && s[i - 0] == 1)
                {
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
        cout << "No" << endl;
        return 0;
    }
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
};