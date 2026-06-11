#include <bits/stdc++.h>
using namespace std;
/* typedef */
typedef long long ll;
typedef pair<ll, ll> pll;
/* constant */
const int INF = 1 << 30;
const ll LINF = 1ll << 50;
const int NIL = -1;
const int MAX = 10000;
const int mod = 1000000007;
const double pi = 3.141592653589;
/* global variables */
double T;
/* function */
/* main */
int main(){
    ll N, K;
    cin >> N >> K;
    vector<pll> v(N);
    ll t, d;
    for (int i = 0; i < N; i++) {
        cin >> t >> d;
        v[i] = pll(d, t);
    }
    sort(v.begin(), v.end(), greater<pll>());

    priority_queue<ll> PQ;
    set<ll> S;
    ll sum = 0;
    ll kind = 0;
    for (int i = 0; i < K; i++) {
        sum += v[i].first;
        if (S.count(v[i].second) == 0) {
            S.insert(v[i].second);
            kind++;
        }
        else { PQ.push(-v[i].first); }
    }

    ll ans = sum + kind * kind;
    for (int i = K; i < N; i++) {
        if (PQ.empty()) break;
        if (S.count(v[i].second) == 0) {
            sum += PQ.top(); PQ.pop();
            sum += v[i].first;
            kind++;
            S.insert(v[i].second);
            ans = max(ans, sum + kind * kind);
        }
    }
    cout << ans << '\n';
}