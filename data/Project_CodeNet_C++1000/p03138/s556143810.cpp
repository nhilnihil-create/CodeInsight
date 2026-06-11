#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cstring>
#include <math.h>
#include <bitset>
#include <queue>
#include <set>
#include <iomanip>
#include <assert.h>
#include <cstdio>

// #include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr long long int INFLL = 1001001001001001LL;
constexpr long long int infll = 1001001001001001LL;
constexpr int INF = 1000000007;
constexpr int inf = 1000000007;
const int mod = 1000000007;

inline bool chmin(ll &a, ll b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}

inline bool chmax(ll &a, ll b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}

template <typename T>
T seinomi(T a)
{
    if (a > 0)
    {
        return a;
    }
    else
    {
        return 0;
    }
}

//桁数取得
template <typename T>
T ketasuu(T num)
{
    return std::to_string(num).length();
}
//整数乗
ll llpow(ll a, ll n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        ll rep = a;
        for (ll i = 1; i < n; i++)
        {
            rep *= a;
        }
        return rep;
    }
}

template <class ForwardIt, class T>
void iota(ForwardIt first, ForwardIt last, T value)
{
    while (first != last)
    {
        *first++ = value;
        ++value;
    }
}

template <typename T>
T amarinasi(T a, T b)
{
    if (a % b == 0)
    {
        return a / b;
    }
    else if (a % b > 0)
    {
        return a / b + 1;
    }
    else
    {
        return a / b - 1;
    }
}

//小数点以下10桁テンプレート（main関数内の最初に貼付け）
//std::cout << std::fixed << std::setprecision(10);

//----------------------------------------------------------------
const double pi = 3.14159265358979323846264;

//進数変換
class base_convert
{
private:
    const char *s;
    int a[128];

public:
    base_convert(const char *s = "0123456789ABCDEF") : s(s)
    {
        int i;
        for (i = 0; s[i]; ++i)
            a[(int)s[i]] = i;
    }
    std::string to(long long p, int q)
    {
        int i;
        if (!p)
            return "0";
        char t[64] = {};
        for (i = 62; p; --i)
        {
            t[i] = s[p % q];
            p /= q;
        }
        return std::string(t + i + 1);
    }
    std::string to(const std::string &t, int p, int q)
    {
        return to(to(t, p), q);
    }
    long long to(const std::string &t, int p)
    {
        int i;
        long long sm = a[(int)t[0]];
        for (i = 1; i < (int)t.length(); ++i)
            sm = sm * p + a[(int)t[i]];
        return sm;
    }
};
base_convert bc;

ll xor1(ll n, ll k, vector<ll> a)
{
    if (k == 0)
    {
        ll tmp_sum = 0;
        for (ll i = 0; i < n; i++)
        {
            tmp_sum += a[i];
        }
        return tmp_sum;
    }
    else if (k == 1)
    {
        ll tmp_sum = 0;
        for (ll i = 0; i < n; i++)
        {
            tmp_sum += a[i];
        }
        ll tmp_sum2 = 0;
        for (ll i = 0; i < n; i++)
        {
            tmp_sum2 += 1 ^ a[i];
        }
        return max(tmp_sum, tmp_sum2);
    }
    else
    {
        k++;
        map<ll, ll> rensou;
        ll max_size = 0;
        for (ll i = 0; i < n; i++)
        {
            string tmp = bc.to(a[i], 2);
            chmax(max_size, tmp.size());
            for (ll i = 0; i < tmp.size(); i++)
            {
                if (tmp[tmp.size() - 1 - i] == '1')
                {
                    rensou[i]++;
                }
            }
        }
        ll ans = 0;
        for (ll i = 0; i < 40; i++)
        {
            ll mask1 = (1LL << i);
            if (!(k & mask1))
            {
                continue;
            }
            ll sum = 0;
            for (ll j = 0; j < i; j++)
            {
                if (rensou[j] > n / 2)
                {
                    sum += llpow(2, j) * rensou[j];
                }
                else
                {
                    sum += llpow(2, j) * (n - rensou[j]);
                }
            }
            sum += llpow(2, i) * rensou[i];
            for (ll j = i + 1; j < 40; j++)
            {
                ll mask2 = (1LL << j);
                if (k & mask2)
                {
                    sum += llpow(2, j) * (n - rensou[j]);
                }
                else
                {
                    sum += llpow(2, j) * rensou[j];
                }
            }
            chmax(ans, sum);
        }
        return ans;
    }
}

ll xor2(ll n, ll k, vector<ll> a)
{

    ll sum = 0;
    for (ll i = 0; i <= k; i++)
    {
        ll tmp = 0;
        for (ll j = 0; j < n; j++)
        {
            tmp += a[j] ^ i;
        }
        chmax(sum, tmp);
    }
    return sum;
}

int main()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    /*if (xor1(n, k, a) != xor2(n, k, a))
    {
        cout << "!!!" << endl;
        cout << xor1(n, k, a) << endl;
        cout << xor2(n, k, a) << endl;
    }*/
    cout << xor1(n, k, a) << endl;
}