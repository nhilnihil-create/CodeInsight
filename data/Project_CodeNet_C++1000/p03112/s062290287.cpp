#include <bits/stdc++.h>
using namespace std;
#define all(n) begin(n), end(n)
struct cww
{
    cww()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);
    }
} star;
const long long INF = numeric_limits<long long>::max();
typedef long long ll;
typedef vector<int> vint;
typedef vector<char> vchar;
typedef vector<vector<int>> vvint;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef unsigned long long ull;
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
template <typename T>
vector<T> make_v(size_t a) { return vector<T>(a); }

template <typename T, typename... Ts>
auto make_v(size_t a, Ts... ts)
{
    return vector<decltype(make_v<T>(ts...))>(a, make_v<T>(ts...));
}
template <typename T, typename V>
typename enable_if<is_class<T>::value == 0>::type
fill_v(T &t, const V &v) { t = v; }

template <typename T, typename V>
typename enable_if<is_class<T>::value != 0>::type
fill_v(T &t, const V &v)
{
    for (auto &e : t)
        fill_v(e, v);
}
int A, B, Q;

vll s, t;
pair<int, int> nears(ll x)
{
    if(A==1)
    {
        return {0,0};
    }
    int left = 0, right = A, idx = 0;
    bool just = false;
    while (right - left > 1)
    {
        int mid = (left + right) / 2;
        if (s[mid] < x)
        {
            left = mid;
        }
        else if (s[mid] == x)
        {
            just = true;
            return {mid,mid};
        }
        else
        {
            right = mid;
        }
    }
    return {left,right};
}
pair<int, int> neart(ll x)
{
    if(B==1)
    {
        return {0,0};
    }
    int left = 0, right = B, idx = 0;
    bool just = false;
    while (right - left > 1)
    {
        int mid = (left + right) / 2;
        if (t[mid] < x)
        {
            left = mid;
        }
        else if (t[mid] == x)
        {
            just = true;
            return {mid,mid};
        }
        else
        {
            right = mid;
        }
    }
    return {left,right};
}
int main()
{

    cin >> A >> B >> Q;
    s.resize(A);
    t.resize(B);
    for (size_t i = 0; i < A; i++)
    {
        cin >> s[i];
    }
    for (size_t i = 0; i < B; i++)
    {
        cin >> t[i];
    }
    vll x(Q);
    for (size_t i = 0; i < Q; i++)
    {
        cin >> x[i];
        
    }
    cout<<endl;
    for (size_t i = 0; i < Q; i++)
    {
        // 神社→寺の順で訪れるとき
        // xに一番近い(左右)神社をさがす
        ll ans = INF;
        auto p = nears(x[i]);
        int l = p.first,r=p.second;
        ll lcost = abs(x[i] - s[l]), rcost = abs(x[i] - s[r]);
        auto pl = neart(s[l]),pr=neart(s[r]);
        ll lleft = pl.first,lright = pl.second;
        ll lcost2 = min(abs(s[l]-t[lleft]),abs(s[l]-t[lright]));
        chmin(ans,lcost+lcost2);
        ll rleft = pr.first,rright = pr.second;
        ll rcost2 = min(abs(s[r]-t[rleft]),abs(s[r]-t[rright]));
        chmin(ans,rcost+rcost2);

        //寺→神社の順のとき
        p = neart(x[i]);
        l = p.first;
        r=p.second;
        lcost = abs(x[i] - t[l]);
        rcost = abs(x[i] - t[r]);
        pl = nears(t[l]);
        pr=nears(t[r]);
        lleft = pl.first;
        lright = pl.second;
        lcost2 = min(abs(t[l]-s[lleft]),abs(t[l]-s[lright]));
        chmin(ans,lcost+lcost2);
        rleft = pr.first;
        rright = pr.second;
        rcost2 = min(abs(t[r]-s[rleft]),abs(t[r]-s[rright]));
        chmin(ans,rcost+rcost2);
        cout<<ans<<endl;
    }
    
    return 0;
}