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

int ruiseki[505][505];
int main()
{
    int n,m,Q;cin >> n >> m >> Q;
    vector<int> l(m);
    vector<int> r(m);
    rep(i,m)
    {
        cin >> l[i] >> r[i];
        ruiseki[l[i]][r[i]]++;
    }
    vector<int> p(Q);
    vector<int> q(Q);
    rep(i, Q)
    {
        cin >> p[i] >> q[i];
    }
    rep(i, 505)
    {
        int temp = 0;
        rep(j,505)
        {
            ruiseki[i][j] = temp+ruiseki[i][j];
            temp = ruiseki[i][j];
        }
    }
    
    rep(i,Q)
    {
        int ans = 0;
        for (int j = p[i]; j <= q[i]; j++)
        {
            ans += ruiseki[j][q[i]]-ruiseki[j][p[i]-1];
        }
        cout << ans << endl;
        
    }



}