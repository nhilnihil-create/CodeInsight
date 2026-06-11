#include "bits/stdc++.h"
#define ll long long
#define PI 3.1415926535897932384626433832795l
#define MAX_NUM 1000000000
#define line printf("-----------------\n");
using namespace std;
int SET(int N, int pos) { return N = N | (1 << pos); }
int RESET(int N, int pos) { return N = N & ~(1 << pos); }
bool CHECK(int N, int pos) { return (bool)(N & (1 << pos)); }
template <typename T>
inline T __lcm(T a, T b)
{
    return (a * b) / __gcd(a, b);
}
struct node
{
    int x, y, i;
};
int dx[] = {0, 1, 0, -1, -1, 1, -1, 1};
int dy[] = {1, 0, -1, 0, 1, 1, -1, -1};

struct DisJointSet
{
    vector<ll> size_;
    vector<ll> parent;

    DisJointSet(ll n)
    {
        size_.resize(n + 1, 1);
        parent.resize(n + 1);

        for (int i = 1; i <= n; i++)
            parent[i] = i;
    }
    ll findSet(ll x)
    {
        if (parent[x] == x)
            return x;
        return parent[x] = findSet(parent[x]);
    }
    void unionSet(int a, int b)
    {
        a = findSet(a);
        b = findSet(b);
        if (a != b)
        {
            if (size_[a] < size_[b])
            {
                swap(a, b);
            }
            parent[b] = a;
            size_[a] += size_[b];
        }
    }
};
ll fun(ll n)
{
    return n * (n - 1) / 2;
}
void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> v;

    vector<ll> v2;

    for (int i = 0; i < m; i++)
    {
        ll x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }
    reverse(v.begin(), v.end());
    DisJointSet dsu(n);
    ll ans = (n - 1) * n / 2;

    v2.push_back(ans);

    for (int i = 0; i < m - 1; i++)
    {
        //int temp = ans;
        ll x, y;
        x = v[i].first;
        y = v[i].second;
        //cout<<x<<" "<<y<<endl;
        ll sizex = dsu.size_[dsu.findSet(x)];
        ll sizey = dsu.size_[dsu.findSet(y)];
        //cout<<sizex<<" + "<<sizey<<endl;
        if (dsu.findSet(x) != dsu.findSet(y))
        {
            dsu.unionSet(x, y);
            int sizexy = dsu.size_[dsu.findSet(x)];
            //cout<<fun(sizexy)<<" "<<fun(sizex)<<" "<<fun(sizey)<<endl;
            ans -= (fun(sizexy) - fun(sizex) - fun(sizey));
            v2.push_back(ans);
        }
        else
        {
            v2.push_back(ans);
        }
        
    }

    for (int i = m-1; i >= 0; i--)
    {
        cout << v2[i] << endl;
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("inputf.txt", "r", stdin);
    //freopen("outputf.txt", "w", stdout);
#endif // ONLINE_JUDGE
    solve();
    return 0;
}