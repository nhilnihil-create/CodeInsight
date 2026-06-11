#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1001001001;
const ll LINF = 1LL << 60;

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

ll cpow(ll num, int n)
{
    ll ret = 1;
    for (int i = 0; i < n; i++)
    {
        ret *= num;
    }
    return ret;
}

const int DIGIT_MAX = 40;
int main()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    bitset<DIGIT_MAX> kbit(k);
    vector<ll> bitcnt(DIGIT_MAX, 0);
    for (int i = 0; i < n; i++)
    {
        bitset<DIGIT_MAX> tmp(a[i]);
        for (int j = 0; j < DIGIT_MAX; j++)
        {
            if (tmp.test(j))
            {
                ++bitcnt[j];
            }
        }
    }
    bool fit_flag = true;
    ll ans = 0;
    for (int i = DIGIT_MAX - 1; i >= 0; i--)
    {
        if (fit_flag && !kbit.test(i))
        {
            ans += bitcnt[i] * cpow(2LL, i);
            continue;
        }
        if (bitcnt[i] >= (n + 1) / 2)
        {
            ans += bitcnt[i] * cpow(2LL, i);
            fit_flag = false;
        }
        else
        {
            ans += (n - bitcnt[i]) * cpow(2LL, i);
        }
    }
    cout << ans << endl;
    return 0;
}
