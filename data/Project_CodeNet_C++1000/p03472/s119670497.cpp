#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1001001001;
const ll LINF = 1LL << 60;
const int MOD = 1'000'000'007;

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

template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}

template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}

// const int MAX = 1010;

int main()
{
    // aが高い剣以外のmaxi_aより高い剣を投げてaでたたく
    ll n, h;
    cin >> n >> h;
    vector<ll> a(n), b(n);
    ll maxi = 0;
    int index = -1;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i];
        if (maxi <= a[i])
        {
            maxi = a[i];
            index = i;
        }
    }
    vector<int> tws;
    for (int i = 0; i < n; i++)
    {
        if (b[i] > maxi && i != index)
        {
            tws.push_back(b[i]);
        }
    }
    sort(tws.begin(), tws.end());
    reverse(tws.begin(), tws.end());
    int tws_index = 0;
    int ans = 0;
    while (h > 0)
    {
        if (h <= b[index])
        {
            h -= b[index];
        }
        else if (tws_index != tws.size())
        {
            h -= tws[tws_index];
            ++tws_index;
        }
        else
        {
            ans += (h - b[index] + maxi - 1) / maxi;
            h = b[index];
            --ans;
        }
        ++ans;
        if (h <= 0)
        {
            cout << ans << endl;
            return 0;
        }
    }
}