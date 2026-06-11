#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>
#include <algorithm>
#include <complex>
#include <array>
using namespace std;
 
#define REP(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define FORR(i,a,b) for (int i=a; i>=b; --i)
#define ALL(c) (c).begin(), (c).end()
 
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;
typedef vector<double> VD;
typedef vector<VD> VVD;

int in() { int x; scanf("%d", &x); return x; }
ll lin() { ll x; scanf("%lld", &x); return x; }

void dfs(int now, int past, ll d, ll &sum, VVI &e){
    sum += d;
    for (int next : e[now]){
        if (next == past) continue;
        dfs(next, now, d + 1, sum, e);
    }
}

int main() {
    ll n;
    cin >> n;
    VL d(n);
    vector<PL> p(n);
    REP(i,n){
        d[i] = lin();
        p[i] = PL(d[i], i);
    }
    sort(ALL(p));
    reverse(ALL(p));

    map<ll, ll> mp;
    REP(i,n) mp[p[i].first] = i;
    VL cnt(n, 1);

    vector<PL> ans;
    REP(i,n-1){
        ll x = p[i].first - (n - 2 * cnt[i]);
        if (!mp.count(x) || mp[x] <= i){
            cout << -1 << endl;
            return 0;
        }
        int j = mp[x];
        cnt[j] += cnt[i];
        ans.push_back(PL(p[i].second, p[j].second));
    }

    VVI e(n);
    for (P p : ans){
        e[p.first].push_back(p.second);
        e[p.second].push_back(p.first);
    }

    ll sum = 0;
    dfs(p[0].second, -1, 0, sum, e);

    if (sum != p[0].first){
        cout << -1 << endl;
        return 0;
    }

    REP(i,n-1){
        printf("%lld %lld\n", ans[i].first + 1, ans[i].second + 1);
    }

    return 0;
}
