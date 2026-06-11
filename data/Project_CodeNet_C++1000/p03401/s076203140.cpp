#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;
const ll C = 1e9+7;

int main() {
    //単調増加、単調減少にならない場合は...
    int N;
    cin >> N;
    vector<ll> A(N+2);
    ll cost = 0;
    A[0] = 0, A[N+1] = 0;

    for(int i=1; i<=N; i++) cin >> A[i];
    for(int i=0; i<=N; i++) cost += abs(A[i] - A[i+1]);

    for(int i=1; i<=N; i++) {
        ll ans = cost;
        if(A[i-1] <= A[i] && A[i] <= A[i+1]) {
            cout << ans << endl;
        }
        else if(A[i-1] >= A[i] && A[i] >= A[i+1]) {
            cout << ans << endl;
        }

        else {
            ans -= min(abs(A[i-1] - A[i]), abs(A[i] - A[i+1])) * 2;
            cout << ans << endl;
        }
    }
}