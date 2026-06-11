#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for (ll i = 0; i < n; i++)
#define rep_r(i, n) for (ll i = n - 1; i >= 0; i--)
#define all(x) x.begin(),x.end()
#define resize(x, n) x.resize(n)
using pll = pair<ll, ll>;
using vl = vector<ll>;
using vvl = vector<vl>;
const ll INF = 1000000000000000000;
const ll mod = 1000000007;
const ll MAX = 100000;
struct edge {
    ll from, to, weight;
    edge(ll f, ll t, ll w) : from(f), to(t), weight(w) { }
};
vector<vector<edge>> edges;
vector<vector<ll>> graph;
vector<bool> visited;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
ll n, m, r, answer;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    vl s(3);
    rep(i, 3) cin >> s[i];
    ll cnt = 0;
    while (not (s[0] == s[1] && s[1] == s[2])) {
        sort(all(s));
        if (s[0] < s[1] && s[1] < s[2]) {
            s[0]++;
            s[1]++;
        } else if (s[0] < s[1] && s[1] == s[2]) {
            s[0] += 2;
        } else if (s[0] == s[1] && s[1] < s[2]) {
            s[0]++;
            s[1]++;
        }
        cnt++;
    }
    printf("%ld\n", cnt);
}