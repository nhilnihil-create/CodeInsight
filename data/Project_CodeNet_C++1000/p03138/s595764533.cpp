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
//#define mod 998244353ll
#define flagcount __builtin_popcount
#define flag(x) (1ll << x)
#define flagadd(bit, x) bit |= flag(x)
#define flagpop(bit, x) bit &= ~flag(x)
#define flagon(bit, i) bit &flag(i)
#define flagoff(bit, i) !(bit & (1ll << i))
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
ll dp[51][2];
int main()
{
    cout << fixed << setprecision(30);
    long long N, K;
    cin >> N >> K;
    vector<long long> A(N);
    for (long long i = 0; i < N; i++)
        cin >> A[i];
    //桁dpを試してみる
    //[(参考)[https://drken1215.hatenablog.com/entry/2019/02/04/013700]
    loop(i, 50)
    {
        dp[i][0] = -1;
        dp[i][1] = -1;
    }
    dp[0][0] = 0;
    loop(d, 50)
    {
        ll count = 0;
        loop(i, N) if (flagon(A[i], (49ll - d))) count++;
        ll plus0 = count * (1ll << (49ll - d));
        ll plus1 = (N - count) * (1ll << (49ll - d));
        //既にKよりも小さいことが確定しているので自由
        if (dp[d][1] != -1)
        {
            dp[d + 1][1] = max(dp[d + 1][1], dp[d][1] + max(plus0, plus1));
        }
        if (dp[d][0] != -1)
        {
            if (flagon(K, (49ll - d)))
            {
                dp[d + 1][1] = max(dp[d + 1][1], dp[d][0] + plus0); //0->1
                dp[d + 1][0] = max(dp[d + 1][0], dp[d][0] + plus1); //0->0
            }
            else
                dp[d + 1][0] = max(dp[d + 1][0], dp[d][0] + plus0); //どうあがいても0->0
        }
    }
    ll ans = max(dp[50][0], dp[50][1]);
    putout(ans);
    return 0;
}
