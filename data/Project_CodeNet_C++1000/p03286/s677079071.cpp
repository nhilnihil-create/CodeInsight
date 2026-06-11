#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const int INF = 1001001001;
const int MOD = 1000000007;

template <typename T>
void print(const T &v);

int main()
{
    ll n;
    cin >> n;
    int flag = 0;
    if (n < 0)
    {
        flag = -1;
    }
    else if (n > 0)
    {
        flag = 1;
    }
    else
    {
        cout << 0 << endl;
        return 0;
    }

    n *= flag;

    vector<int> ans;

    for (int i = 0; n != 0; i++)
    {
        ll waru = pow(2, i + 1);
        if (n % waru != 0)
        {
            ans.push_back(1);
            if (i % 2 == 0)
            {
                n -= (waru / 2) * flag;
            }
            else
            {
                n += (waru / 2) * flag;
            }
        }
        else
        {
            ans.push_back(0);
        }
    }
    reverse(ans.begin(), ans.end());
    for (int a : ans)
    {
        cout << a;
    }
    cout << endl;
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
