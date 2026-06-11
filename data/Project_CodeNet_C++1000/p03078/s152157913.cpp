#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;

#define mt make_tuple
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sqr(x) ((ll)(x) * (x))

int main()
{
    int x, y, z, k;
    cin >> x >> y >> z >> k;

    vector<ll> a(x);
    for(auto &u : a)
        cin >> u;
    vector<ll> b(y);
    for(auto &u : b)
        cin >> u;
    vector<ll> c(z);
    for(auto &u : c)
        cin >> u;

    sort(rall(c));

    priority_queue<pair<ll, int>> pq;

    for(int i = 0; i < x; ++i)
    {
        for(int j = 0; j < y; ++j)
        {
            pq.push({a[i]+b[j]+c[0], 0});
        }
    }

    for(int i = 0; i < k; ++i)
    {
        auto top = pq.top();
        pq.pop();

        cout << top.fi << '\n';

        if(top.se == z-1)
            continue;

        pq.push({top.fi - c[top.se] + c[top.se+1], top.se+1});
    }

    return 0;
}
