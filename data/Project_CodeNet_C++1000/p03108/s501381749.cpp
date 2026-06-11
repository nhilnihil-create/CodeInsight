#include<bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl
typedef long long ll;
using namespace std;
int static fast = [](){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0); return 0;
}();
ll find(vector<ll>& grp, int x) {
    if (grp[x] == x)
        return x;
    return grp[x] = find(grp, grp[x]);
}

int main() {
    int n, m, a, b;
    cin >> n >> m;
    vector<pair<int, int>> edge;
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        edge.push_back({a-1, b-1});
    }
    vector<ll> grp(n, 0);
    vector<ll> grp_size(n, 1);
    for(int i = 0; i < n; i++)
        grp[i] = i;
    ll cnt = ll(n)*ll(n-1) / 2;
    vector<ll> ans = {cnt};

    for(int i = m-1; i >= 0; i--) {
        int r1 = find(grp, edge[i].first);
        int r2 = find(grp, edge[i].second);
        if (r1 != r2) {
            ll sz1 = grp_size[r1] * (grp_size[r1]-1) / 2;
            ll sz2 = grp_size[r2] * (grp_size[r2]-1) / 2;
            cnt += sz1 + sz2;
            grp_size[r1] = grp_size[r2] = grp_size[r1]+grp_size[r2];
            cnt -= grp_size[r2] * (grp_size[r2]-1) / 2;
            grp[r1] = grp[r2] = min(grp[r2], grp[r2]);

        }
        ans.push_back(cnt);
    }
    ans.pop_back();
    reverse(ans.begin(), ans.end());
    for(auto val: ans) {
        cout << val << endl;
    }
    return 0;
}


