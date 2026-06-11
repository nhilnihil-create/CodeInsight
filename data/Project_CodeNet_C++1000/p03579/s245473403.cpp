#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <array>
#include <queue>
#include <map>
#include <set>
#include <functional>

using namespace std;

#define ll long long
constexpr ll inf = 1e9+7;

int main () {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, M;
    cin>>N>>M;
    vector<ll> v(N+1, 0);
    map<ll, set<ll>> edge;
    for (ll m = 0; m < M; m++) {
        ll a, b;
        cin>>a>>b;
        edge[a].insert(b);
        edge[b].insert(a);
    }

    ll v_num[3] = {0};
    function<bool(ll)> dfs = [&](ll at) {
        if (edge.count(at) > 0) {
            for (ll next : edge[at]) {
                if (v[next] == 0) {
                    v[next] = v[at] * -1;
                    v_num[v[next]+1]++;
                    if (dfs(next)) return true;
                } else if (v[next] == v[at]) return true;
            }
        }
        return false;
    };
    v_num[2]++;
    v[1] = 1;
    if (dfs(1) == false) cout<<(v_num[0]*v_num[2]-M)<<endl;
    else cout<<(N*(N-1)/2-M)<<endl;
    return 0;
}