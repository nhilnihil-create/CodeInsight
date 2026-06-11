#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
#define ll long long
#define ld long double
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define PI 3.14159265358979323846
#define sz(x) ((int)(x).size())
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)

const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;


int main()
{
    int n,m;cin >> n >> m;
    vector<vector<ll> > n_cake(n, vector<ll>(3));
    rep(i, n)
    {
        cin >> n_cake[i][0] >> n_cake[i][1] >> n_cake[i][2];
    }

    vector<ll> sortable(n);
    ll mx = 0;
    rep(i, 8)
    {
        rep(i, n) sortable[i] = 0;
        rep(j,3)
        {
            if(i & (1 << j))
            {
                rep(k,n)sortable[k] += n_cake[k][j];
                continue;
            }
            rep(k, n) sortable[k] -= n_cake[k][j];
        }
        sort(sortable.begin(),sortable.end(), greater<ll>());
        ll temp = 0;
        rep(i,m) temp += sortable[i];
        mx = max(mx, temp);
    }
    cout << mx << endl;
}