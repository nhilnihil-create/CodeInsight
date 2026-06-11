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

int judge(int num)
{
    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int q;
    cin >> q;
    vector<int> l(q), r(q);
    for (int i = 0; i < q; i++)
    {
        cin >> l[i] >> r[i];
    }
    vector<int> sums(500001, 0);
    vector<int> tt(500001, 0);
    for (int i = 3; i < 500000; i += 2)
    {
        sums[i] = judge(i);
    }
    sums[2] = 1;
    for (int i = 3; i < 500000; i += 2)
    {
        if (sums[i] == 0)
        {
            continue;
        }
        if (sums[(i + 1) / 2] == 1)
        {
            tt[i] = 1;
        }
    }
    for (int i = 0; i < 500000; i++)
    {
        tt[i + 1] += tt[i];
    }
    for (int i = 0; i < q; i++)
    {
        cout << tt[r[i]] - tt[l[i] - 1] << endl;
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