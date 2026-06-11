#include <bits/stdc++.h>
#define rep(i, n) for(ll i = 0; i < n; i++)
#define repr(i, n) for(ll i = n; i >= 0; i--)
#define reprr(i, m, n) for (ll i = m; i < n; i++)
#define inf 2e9
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;


int main()
{
    ll X, Y, Z, K; cin >> X >> Y >> Z >> K;
    vll A(X); rep(i, X) cin >> A[i];
    vll B(Y); rep(i, Y) cin >> B[i];
    vll C(Z); rep(i, Z) cin >> C[i];
    sort(all(A));
    reverse(all(A));
    sort(all(B));
    reverse(all(B));
    sort(all(C));
    reverse(all(C));

    priority_queue<pair<ll, vector<ll>>> que;
    vvll used;
    que.push({A[0] + B[0] + C[0], {0, 0, 0}});

    rep(i, K) {
        pair<ll, vector<ll>> elem;
        do {
            elem = que.top(); que.pop();
        } while (find(all(used), elem.second) != used.end());
        cout << elem.first << endl;
        used.push_back(elem.second);
        ll a = elem.second[0], b = elem.second[1], c = elem.second[2];
        //cout << "a: " << a << ", b: " << b << ", c: " << c << endl;
        //cout << "a: " << A[a] << ", b: " << B[b] << ", c: " << C[c] << endl;
        if (a < X - 1) que.push({A[a+1] + B[b] + C[c], {a+1, b, c}});
        if (b < Y - 1) que.push({A[a] + B[b+1] + C[c], {a, b+1, c}});
        if (c < Z - 1) que.push({A[a] + B[b] + C[c+1], {a, b, c+1}});
    }
    return 0;
}