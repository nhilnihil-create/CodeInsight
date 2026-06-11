#include <bits/stdc++.h>
using namespace std;
using pint = pair<int, int>;
using ll = long long;
using ull = unsigned long long;
using vll = vector<long long>;
using pll = pair<ll, ll>;
#define FOR(i, begin, end) for (int i = (begin), i##_end_ = (end); i < i##_end_; i++)
#define IFOR(i, begin, end) for (int i = (end)-1, i##_begin_ = (begin); i >= i##_begin_; i--)
#define REP(i, n) FOR(i, 0, n)
#define IREP(i, n) IFOR(i, 0, n)
#define VREP(s, ite) for (auto ite = s.begin(); ite != s.end(); ++ite)
#define FI first
#define SE second
#define ALL(v) v.begin(),v.end()
//#define endl "\n"
#define ciosup  \
    cin.tie(0); \
    ios::sync_with_stdio(false);
#define eb emplace_back
#define vint vector<int>
constexpr ll INF = 1e18 + 7LL;
constexpr ll MOD = 1e9 + 7;

template <typename T>
istream& operator>>(istream& is, vector<T> &v)
{
    for (int i = 0; i < v.size(); ++i)
    {
        is >> v[i];
    }
    return is;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v)
{
    for (int i = 0; i < v.size()-1; ++i)
    {
        os << v[i] << " ";
    }
    if (v.size() > 0){
        os << v[v.size() - 1] << endl;
    }
    return os;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<pll> sushi(n);
    REP(i,n){
        cin >> sushi[i].SE >> sushi[i].FI;
    }
    sort(sushi.begin(), sushi.end());
    reverse(sushi.begin(), sushi.end());
    ll ans = 0;
    unordered_map<int,int> kind;
    priority_queue<int> pque2;
    priority_queue<int, vint, greater<int>> pque;
    ll kindval = 0;
    REP(i, k)
    {
        ans += sushi[i].FI;
        ++kind[sushi[i].SE];
        if (kind[sushi[i].SE] > 1){
            pque.push(sushi[i].FI);
        }else{
            ++kindval;
        }
    }
    FOR(i,k,n)
    {
        ++kind[sushi[i].SE];
        if (kind[sushi[i].SE] == 1)
        {
            pque2.push(sushi[i].FI);
        }
    }
    ans += kindval * kindval;
    ll now = ans;
    while (pque.size() > 0 && pque2.size() > 0)
    {
        now -= pque.top();
        pque.pop();
        now += pque2.top();
        pque2.pop();
        ++kindval;
        now += kindval * kindval - (kindval - 1) * (kindval - 1);
        ans = max(now, ans);
    }
    cout << ans << endl;
}