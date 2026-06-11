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
    int n, k;
    string s;
    cin >> n >> k >> s;
    vector<int> v;
    bool flag = true; // '1'が継続している間はtrue
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if ((flag && s[i] == '1') || (!flag && s[i] == '0'))
        {
            ++cnt;
        }
        else
        {
            v.push_back(cnt);
            cnt = 1;
            flag = !(flag);
        }
    }
    v.push_back(cnt);
    v.push_back(0);
    v.push_back(0);
    if (v.size() <= k * 2 + 1)
    {
        int total = 0;
        for (int num : v)
        {
            total += num;
        }
        cout << total << endl;
        return 0;
    }
    int total = 0;
    for (int i = 0; i < k * 2 + 1; i++)
    {
        total += v[i];
    }
    int maxi = total;
    for (int i = 0; i < v.size() - (k * 2) - 3; i += 2)
    {
        total -= v[i];
        total -= v[i + 1];
        total += v[i + 2 * k + 1];
        total += v[i + 2 * k + 2];
        maxi = max(maxi, total);
    }
    cout << maxi << endl;
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