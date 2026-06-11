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
    cin >> n;
    vector<int> b(n);
    stack<int> ans;
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    while (b.size() != 0)
    {
        int index = -1;
        for (int i = 0; i < b.size(); i++)
        {
            if (b[i] == i + 1)
            {
                index = i;
            }
        }
        if (index == -1)
        {
            cout << -1 << endl;
            return 0;
        }
        ans.push(index + 1);
        vector<int> tmp;
        for (int i = 0; i < b.size(); i++)
        {
            if (i != index)
            {
                tmp.push_back(b[i]);
            }
        }
        b = tmp;
    }
    while (!ans.empty())
    {
        cout << ans.top() << endl;
        ans.pop();
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
            cout << ' ';
        cout << v[i];
    }
    cout << endl;
}