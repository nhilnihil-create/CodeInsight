#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
using ll = long long;
using vec = vector<ll>;
using vect = vector<double>;
using Graph = vector<vector<ll>>;
#define loop(i, n) for (ll i = 0; i < n; i++)
#define Loop(i, m, n) for (ll i = m; i < n; i++)
#define pool(i, n) for (ll i = n; i >= 0; i--)
#define Pool(i, m, n) for (ll i = n; i >= m; i--)
#define mod 1000000007ll
#define flagcount __builtin_popcount
#define flag(x) (1 << x)
#define flagadd(bit, x) bit |= flag(x)
#define flagpop(bit, x) bit &= ~flag(x)
#define flagon(bit, i) bit &flag(i)
#define flagoff(bit, i) !(bit & (1 << i))
#define all(v) v.begin(), v.end()
#define low2way(v, x) lower_bound(all(v), x)
#define high2way(v, x) upper_bound(all(v), x)
#define idx_lower(v, x) (distance(v.begin(), low2way(v, x)))  //配列vでx未満の要素数を返す
#define idx_upper(v, x) (distance(v.begin(), high2way(v, x))) //配列vでx以下の要素数を返す
#define idx_lower2(v, x) (v.size() - idx_lower(v, x))         //配列vでx以上の要素数を返す
#define idx_upper2(v, x) (v.size() - idx_upper(v, x))         //配列vでxより大きい要素の数を返す
#define putout(a) cout << a << endl
#define Gput(a, b) G[a].push_back(b)
#define Sum(v) accumulate(all(v), 0ll)
#define gcd(x, y) __gcd(x, y)
ll ctoi(char c)
{
    if (c >= '0' && c <= '9')
    {
        return c - '0';
    }
    return 0;
}
template <typename T>
T lcm(T x, T y)
{
    T z = gcd(x, y);
    return x * y / z;
}
template <typename T>
bool primejudge(T n)
{
    if (n < 2)
        return false;
    else if (n == 2)
        return true;
    else if (n % 2 == 0)
        return false;
    double sqrtn = sqrt(n);
    for (T i = 3; i < sqrtn + 1; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
        i++;
    }
    return true;
}
//場合によって使い分ける
//const ll dx[4]={1,0,-1,0};
//const ll dy[4]={0,1,0,-1};
const ll dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const ll dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
//2次元配列の宣言
//vector<vector<ll>> field(h, vector<ll>(w));

int main()
{
    cout << fixed << setprecision(30);
    ll A, B, Q;
    cin >> A >> B >> Q;
    vec s(A), t(B);
    loop(i, A) cin >> s[i];
    loop(i, B) cin >> t[i];
    s.push_back(-1e18);
    s.push_back(1e18);
    t.push_back(-1e18);
    t.push_back(1e18);
    sort(all(s));
    sort(all(t));
    A += 2;
    B += 2;
    loop(i, Q)
    {
        ll x;
        cin >> x;
        ll sll, srr, tll, trr;
        sll = idx_lower(s, x) - 1;
        srr = sll + 1;
        tll = idx_lower(t, x) - 1;
        trr = tll + 1;
        ll sl, sr, tl, tr;
        sl = s[sll];
        sr = s[srr];
        tl = t[tll];
        tr = t[trr];
        ll ans = 2e18;
        //8パターン
        ans = min(ans, abs(x - sl) + abs(sl - tl));
        ans = min(ans, abs(x - sl) + abs(sl - tr));
        ans = min(ans, abs(x - sr) + abs(sr - tl));
        ans = min(ans, abs(x - sr) + abs(sr - tr));
        ans = min(ans, abs(x - tl) + abs(tl - sl));
        ans = min(ans, abs(x - tl) + abs(tl - sr));
        ans = min(ans, abs(x - tr) + abs(tr - sl));
        ans = min(ans, abs(x - tr) + abs(tr - sr));
        putout(ans);
    }
    return 0;
}
