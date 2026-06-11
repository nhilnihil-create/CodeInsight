#include <bits/stdc++.h>
using namespace std;
/* typedef */
typedef long long ll;
typedef pair<int, int> pii;
/* constant */
const int INF = 1 << 30;
const ll LINF = 1LL << 50;
const int NIL = -1;
const int MAX = 10000;
const int mod = 1000000007;
const double pi = 3.141592653589;
/* global variables */
/* function */
/* main */
int main(){
    int N, K, a;
    cin >> N >> K;
    vector<ll> pos, neg;
    pos.push_back(0);
    for (int i = 0; i < N; i++) {
        cin >> a;
        if (a > 0) pos.push_back(a);
        else neg.push_back(-a);
    }
    neg.push_back(0);
    reverse(neg.begin(), neg.end());
    ll ans = LINF;
    for (int pi = 0; pi <= K; pi++) {
        int ni = K - pi;
        if (pi >= pos.size() || ni >= neg.size()) continue;
        ll tmp = min(pos[pi] * 2 + neg[ni], pos[pi] + neg[ni] * 2);
        ans = min(tmp, ans);
    }
    cout << ans << '\n';
}
