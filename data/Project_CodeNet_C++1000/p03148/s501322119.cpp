#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;

int main() 
{
    int n, k;
    cin >> n >> k;

    set<int> S;
    vector<pair<int,int>> V0;
    rep(i,n) {
        int t, d;
        cin >> t >> d;
        V0.emplace_back(t,d);
    }
    sort(V0.rbegin(), V0.rend());

    vector<pair<int,int>> V;
    for (auto v : V0) {
        if (S.find(v.first) == S.end()) {
            S.insert(v.first);
            V.emplace_back(v.second, 1);
        } else {
            V.emplace_back(v.second, 0);
        }
    }
    sort(V.rbegin(), V.rend());

    ll x = 0;
    ll y = 0;
    auto f = [&](){return x + y*y;};
    rep(i,k) {
        x += V[i].first;
        if(V[i].second == 1) y++;
    }

    ll ans = f();
    vector<int> T;
    for(int i= k; i<n; i++) {
        if(V[i].second == 1) T.push_back(V[i].first);
    }
    sort(T.rbegin(), T.rend());
    vector<int> W;
    rep(i,k) {
        if (V[i].second == 0) W.push_back(V[i].first);
    }
    sort(W.begin(), W.end());

    rep(i, T.size()) {
        if (i == W.size()) break;
        y++;
        x += T[i];
        x -= W[i];
        ans = max(f(), ans);
    }

    cout << ans << endl;

    return 0;
}
