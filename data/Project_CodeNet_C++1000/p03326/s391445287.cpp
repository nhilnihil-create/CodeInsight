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
    ll N, M;
    cin >> N >> M;
    vec X(N), Y(N), Z(N);
    loop(i, N) cin >> X[i] >> Y[i] >> Z[i];
    vector<pair<ll, ll>> pair1(N);
    vector<pair<ll, ll>> pair2(N);
    vector<pair<ll, ll>> pair3(N);
    vector<pair<ll, ll>> pair4(N);
    vector<pair<ll, ll>> pair5(N);
    vector<pair<ll, ll>> pair6(N);
    vector<pair<ll, ll>> pair7(N);
    vector<pair<ll, ll>> pair8(N);
    loop(i, N) pair1[i] = make_pair(X[i] + Y[i] + Z[i], i);
    loop(i, N) pair2[i] = make_pair(-X[i] + Y[i] + Z[i], i);
    loop(i, N) pair3[i] = make_pair(X[i] - Y[i] + Z[i], i);
    loop(i, N) pair4[i] = make_pair(X[i] + Y[i] - Z[i], i);
    loop(i, N) pair5[i] = make_pair(-X[i] - Y[i] + Z[i], i);
    loop(i, N) pair6[i] = make_pair(X[i] - Y[i] - Z[i], i);
    loop(i, N) pair7[i] = make_pair(-X[i] + Y[i] - Z[i], i);
    loop(i, N) pair8[i] = make_pair(-X[i] - Y[i] - Z[i], i);
    sort(all(pair1));
    reverse(all(pair1));
    sort(all(pair2));
    reverse(all(pair2));
    sort(all(pair3));
    reverse(all(pair3));
    sort(all(pair4));
    reverse(all(pair4));
    sort(all(pair5));
    reverse(all(pair5));
    sort(all(pair6));
    reverse(all(pair6));
    sort(all(pair7));
    reverse(all(pair7));
    sort(all(pair8));
    reverse(all(pair8));
    vector<vector<ll>> ans(8, vector<ll>(3));
    loop(i, M)
    {
        vec ind(8);
        ind[0] = pair1[i].second;
        ind[1] = pair2[i].second;
        ind[2] = pair3[i].second;
        ind[3] = pair4[i].second;
        ind[4] = pair5[i].second;
        ind[5] = pair6[i].second;
        ind[6] = pair7[i].second;
        ind[7] = pair8[i].second;
        loop(j, 8)
        {
            ans[j][0] += X[ind[j]];
            ans[j][1] += Y[ind[j]];
            ans[j][2] += Z[ind[j]];
        }
    }
    vec ANS(8);
    loop(i, 8)
    {
        ANS[i] = abs(ans[i][0]) + abs(ans[i][1]) + abs(ans[i][2]);
    }
    sort(all(ANS));
    putout(ANS[7]);
    return 0;
}
