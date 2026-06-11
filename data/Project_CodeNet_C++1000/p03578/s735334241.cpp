#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
using Graph = vector<vector<int>>;
#define MOD 1000000007
#define MOD2 998244353
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;

map<ll, ll> mp;

int main(){
    int n, m;
    bool flag = true;
    cin >> n;

    ll d[n];
    rep(i, n) cin >> d[i];

    cin >> m;
    ll t[m];
    rep(j, m) cin >> t[j];

    rep(i, n) mp[d[i]]++;

    rep(j, m){
        if (mp[t[j]] > 0) mp[t[j]]--;
        else flag = false;
    }

    if (flag) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}