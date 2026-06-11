#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using VVI = vector<vector<int>>;
const int INF = 1001001001;
const int MOD = 1000000007;

template <typename T>
void print(const T &v);

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> sws(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++)
    {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++)
        {
            int s;
            cin >> s;
            sws[i][s - 1] = 1;
        }
    }
    vector<int> ps(m);
    for (int i = 0; i < m; i++)
    {
        cin >> ps[i];
    }
    int ans = 0;
    for (int i = 0; i < (1 << n); i++)
    {
        bitset<10> s(i);
        int total = 0;
        for (int k = 0; k < m; k++)
        {
            int cnt = 0;
            for (int j = 0; j < n; j++)
            {
                if (s.test(j) && sws[k][j] == 1)
                {
                    cnt++;
                }
            }
            if (cnt % 2 == ps[k])
            {
                total++;
            }
        }
        if (total == m)
        {
            ans++;
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
            cout << " ";
        cout << v[i];
    }
    cout << endl;
}