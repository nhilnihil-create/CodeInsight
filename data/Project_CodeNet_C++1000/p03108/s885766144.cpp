#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
typedef long long ll;
typedef long double ld;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define fi first
#define se second
#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
typedef long long ll;
typedef long double ld;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define fi first
#define se second

vi u, v;
ll ans;

class DSU
{
private:
    int n;
    vector<ll> vel, rod;
public:
    DSU(int n) : n(n)
    {
        vel.assign(n,1);
        rod.resize(n);
        for(int i = 0; i < n; ++i)
            rod[i] = i;        
    }

    int dobiRod(int a)
    {
        while(a!=rod[a])
        {
            rod[a] = rod[rod[a]];
            a = rod[a];
        }
        
        return a;
    }
    
    void unite(int a, int b)
    {
        a = dobiRod(a), b = dobiRod(b);

        if(a == b)
            return;
        
        ans -= 1LL * vel[a] * vel[b];
        if(vel[a] > vel[b])
            swap(a,b);

        vel[b] += vel[a];
        rod[a] = rod[b];
    }
};


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    DSU pov(n);
    
    u.resize(m);
    v.resize(m);
    ans = n * 1LL * (n-1) / 2LL;

    for(int i = 0; i < m; ++i)
    {
        cin >> u[i] >> v[i], --u[i], --v[i];
    }

    vector<ll> kon;

    for(int i = m-1; ~i; --i)
    {
        kon.pb(ans);
        pov.unite(u[i],v[i]);
    }

    reverse(all(kon));
    
    for(auto z : kon)
        cout << z << '\n';
}
