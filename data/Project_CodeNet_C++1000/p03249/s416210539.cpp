#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
vector<l_l> D;
ll SIZE[100500];
map<ll, ll> mp;
ll dist[100050];
vector<ll> pathes[100050];
ll ONED;

void dfs(int now, int from) {
    for(auto to : pathes[now]) {
        if(to == from) continue;
        dist[to] = dist[now] + 1;
        dfs(to, now);
    }
}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    D.resize(N);
    for(int i = 1; i <= N; i++) {
        cin >> D[i-1].first;
        D[i-1].second = i;
        SIZE[i] = 1;
        mp[D[i-1].first] = i;
    }
    ONED = D[0].first;
    sort(D.begin(), D.end(), greater<l_l>());
    vector<l_l> ans;
    for(int i = 0; i < N - 1; i++) {
        int index = D[i].second;
        ll val = D[i].first;
        val += SIZE[index] - (N - SIZE[index]);
        if(SIZE[index] * 2 >= N) {
            cout << -1 << endl;
            return 0;
        }
        if(mp[val] == 0) {
            cout << -1 << endl;
            return 0;
        }
        SIZE[mp[val]] += SIZE[index];
        ans.push_back({index, mp[val]});
        pathes[index].push_back(mp[val]);
        pathes[mp[val]].push_back(index);
    }
    dfs(1, -1);
    ll distsum = 0;
    for(int i = 1; i <= N; i++) distsum += dist[i];
    if(distsum != ONED) {
        cout << -1 << endl;
        return 0;
    }
    for(auto e : ans) cout << e.first << " " << e.second << endl;
    return 0;
}