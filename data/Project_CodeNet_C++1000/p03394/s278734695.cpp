//#include <tourist>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> p;
const int INF = 1e9;
const ll LINF = ll(1e18);
const int MOD = 1000000007;
const int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
const int Dx[8] = {0, 1, 1, 1, 0, -1, -1, -1}, Dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
#define yes cout << "Yes" << endl
#define YES cout << "YES" << endl
#define no cout << "No" << endl
#define NO cout << "NO" << endl
#define rep(i, n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define debug(v)          \
    cout << #v << ":";    \
    for (auto x : v)      \
    {                     \
        cout << x << ' '; \
    }                     \
    cout << endl;
template <class T>
bool chmax(T &a, const T &b)
{
    if (a < b)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b)
{
    if (b < a)
    {
        a = b;
        return 1;
    }
    return 0;
}
//cout<<fixed<<setprecision(15);有効数字15桁
//-std=c++14
//-std=gnu++17
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
ll n;
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    if (n == 3)
    {
        cout << 2 << "\n";
        cout << 5 << "\n";
        cout << 63 << "\n";
        return 0;
    }
    if (n == 4)
    {
        cout << 2 << "\n";
        cout << 5 << "\n";
        cout << 20 << "\n";
        cout << 63 << "\n";
        return 0;
    }
    vector<ll> two, three;
    for (ll i = 1; i <= 30000; i++)
    {
        if (i % 3 == 0)
            three.push_back(i);
        else if (i % 2==0)
            two.push_back(i);
    }
    int m = n - 2;
    vector<ll> ans;
    if (n % 2)
    {
        int count = m / 4;
        int three_c = count * 4;
        int two_c = n - count;
        int ii = 3;
        rep(i, 3)
        {
            ans.push_back(three[i]);
        }
        ans.push_back(two[0]);
        ans.push_back(two[1]);
        int j = 2;
        while (ans.size() + 4 <= n && ii + 3 < three.size())
        {
            ans.push_back(three[ii]);
            ii++;
            ans.push_back(three[ii]);
            ii++;
            ans.push_back(three[ii]);
            ii++;
            ans.push_back(three[ii]);
            ii++;
        }
        while (ans.size() + 2 <= n && j + 1 < two.size())
        {
            ans.push_back(two[j]);
            j++;
            ans.push_back(two[j]);
            j++;
        }
    }
    else
    {
        int count = m / 4;
        int three_c = count * 4;
        int two_c = n - count;
        int ii = 4;
        rep(i, 4)
        {
            ans.push_back(three[i]);
        }
        ans.push_back(two[0]);
        ans.push_back(two[1]);
        int j = 2;
        while (ans.size() + 4 <= n && ii + 3 < three.size())
        {
            ans.push_back(three[ii]);
            ii++;
            ans.push_back(three[ii]);
            ii++;
            ans.push_back(three[ii]);
            ii++;
            ans.push_back(three[ii]);
            ii++;
        }
        while (ans.size() + 2 <= n && j + 1 < two.size())
        {
            ans.push_back(two[j]);
            j++;
            ans.push_back(two[j]);
            j++;
        }
    }
    rep(i, n) cout << ans[i] << "\n";
}
