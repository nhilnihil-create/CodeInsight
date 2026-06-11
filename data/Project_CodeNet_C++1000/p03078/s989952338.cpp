#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;
using ll = long long;
using P = pair<ll, vector<ll>>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int X, Y, Z, K; cin >> X >> Y >> Z >> K;
    vector<ll> A(X), B(Y), C(Z);
    for (int i = 0; i < X; i++) cin >> A[i];
    for (int i = 0; i < Y; i++) cin >> B[i];
    for (int i = 0; i < Z; i++) cin >> C[i];
    sort(A.begin(), A.end(), greater<ll>());
    sort(B.begin(), B.end(), greater<ll>());
    sort(C.begin(), C.end(), greater<ll>());

    priority_queue<P> que;
    set<vector<ll>> s;
    que.push(P(A[0]+B[0]+C[0], {0, 0, 0}));
    for (int i = 0; i < K; i++) {
        P p = que.top(); que.pop();
        cout << p.first << "\n";
        ll a = p.second[0];
        ll b = p.second[1];
        ll c = p.second[2];
        vector<ll> v = p.second;
        if (a+1 < X) {
            vector<ll> w = {a+1, b, c};
            if (!s.count(w)) {
                que.push(P(A[a+1]+B[b]+C[c], w));
                s.insert(w);
            }
        }
        if (b+1 < Y) {
            vector<ll> w = {a, b+1, c};
            if (!s.count(w)) {
                que.push(P(A[a]+B[b+1]+C[c], w));
                s.insert(w);
            }
        }
        if (c+1 < Z) {
            vector<ll> w = {a, b, c+1};
            if (!s.count(w)) {
                que.push(P(A[a]+B[b]+C[c+1], w));
                s.insert(w);
            }
        }
    }
}