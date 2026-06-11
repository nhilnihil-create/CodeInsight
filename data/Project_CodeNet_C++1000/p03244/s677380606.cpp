#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

#define rep(i, N) for (ll i = 0; i < (N); i++)
#define FOR(i, a, b) for (ll i = (a), i < (N): i++)
#define all(A) (A).begin(), (A).end()

int main(){
    int N;
    cin >> N;
    int V[N];
    rep(i, N) cin >> V[i];
    vector<pii> A(1e5 + 10), B(1e5+10);
    rep(i, 1e5+10) {
        A[i].first = 0;
        B[i].first = 0;
        A[i].second = i;
        B[i].second = i;
    }
    rep(i, N) {
        if (i % 2 == 0) {
            A[V[i]].first++;
        }
        else B[V[i]].first++;
    }

    sort(all(A), [](pii a, pii b) {return a.first > b.first;});
    sort(all(B), [](pii a, pii b) {return a.first > b.first;});

    int ans = 0;
    if (A[0].second == B[0].second) {
        ans = N - max(A[0].first + B[1].first, A[1].first + B[0].first);
    }
    else ans = N - A[0].first - B[0].first;

    cout << ans << endl;

    return 0;
}
