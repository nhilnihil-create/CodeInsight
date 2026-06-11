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
    int n;
    cin >> n;
    --n;
    vector<vector<int>> vecs(n, vector<int>(3));
    rep(i, n)
    {
        cin >> vecs[i][0] >> vecs[i][1] >> vecs[i][2];
    }
    for (int i = 0; i < n; i++)
    {
        int now = vecs[i][1] + vecs[i][0];
        for (int j = i + 1; j < n; j++)
        {
            int c = vecs[j][0], s = vecs[j][1], f = vecs[j][2];
            now = max(s, ((now + f - 1) / f) * f); // 発車時間
            now += c;
        }
        cout << now << endl;
    }
    cout << 0 << endl;
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
