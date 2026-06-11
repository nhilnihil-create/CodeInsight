#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
vector<pair<int, int>> to[100010];
bool visited[100010];
ll dist[100010];

int main() {
    int n;
    cin >> n;
    vector<ll>a(n);
    vector<ll>b(n);
    vector<ll>c(n);
    rep(i,0,n){
        cin >> a[i];
    }
    rep(i,0,n){
        cin >> b[i];
    }
    rep(i,0,n){
        cin >> c[i];
    }
    sort(a.begin(), a.end());
    sort(c.begin(), c.end());
    ll ans = 0;
    rep(i, 0, n){
        auto aindex = lower_bound(a.begin(), a.end(), b[i]);
        ll ac = aindex - a.begin();
        auto cindex = upper_bound(c.begin(), c.end(), b[i]);
        ll cc =  c.end() - cindex;
        ans += ac * cc;
    }
    cout << ans << endl;
   return 0;
}
