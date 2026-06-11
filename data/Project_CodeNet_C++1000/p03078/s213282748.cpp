#include <bits/stdc++.h>
#define REP(i, s, n) for (int i = s; i < (int)(n); i++)
#define ALL(a) a.begin(), a.end()
#define MOD 1000000007
using namespace std;
using ll = long long;

int main() {
    int X, Y, Z, K; cin >> X >> Y >> Z >> K;
    vector<ll> A(X), B(Y), C(Z);
    REP(i, 0, X) cin >> A[i];
    REP(i, 0, Y) cin >> B[i];
    REP(i, 0, Z) cin >> C[i];


    vector<ll> AB(X * Y);
    REP(i, 0, X) {
        REP(j, 0, Y) {
            AB[Y * i + j] = A[i] + B[j];
        }
    }

    sort(ALL(AB), greater<>());
    sort(ALL(C), greater<>());

    priority_queue<ll, vector<ll>, greater<ll>> pq;
    REP(i, 0, Z) {
        // cout << "# i : " << i << " : " << C[i] << endl;
        REP(j, 0, min((int)AB.size(), K)) {
            if ((int)pq.size() < K) {
                pq.push(C[i] + AB[j]);
                // cout << "--> pushed "  << C[i] + AB[j] << endl;
            } else {
                if (pq.top() >= C[i] + AB[j]) break;
                pq.pop();
                pq.push(C[i] + AB[j]);
                // cout << "--> pushed "  << C[i] + AB[j] << endl;
            }
        }
    }

    vector<ll> ans(K);
    REP(i, 0, K) {
        ans[K - i - 1] = pq.top();
        pq.pop();
    }
    for (auto a : ans) cout << a << endl;
    return 0;
}