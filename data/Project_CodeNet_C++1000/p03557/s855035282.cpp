#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1LL << 60;
const int MAX = 1000000010;
const ll MOD = 1000000007;

int main() {
    int N; cin >> N;
    vector<int> A(N);
    vector<int> B(N);
    vector<int> C(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) cin >> B[i];
    for (int i = 0; i < N; i++) cin >> C[i];

    sort(A.begin(), A.end());
    sort(C.begin(), C.end());
    ll sum = 0;
    for (int j = 0; j < N; j++) {
        auto itr_A = lower_bound(A.begin(), A.end(), B[j]);
        auto itr_C = lower_bound(C.begin(), C.end(), B[j] + 1);
        int a = distance(A.begin(), itr_A);
        int c = distance(itr_C, C.end());
        sum += (ll)a * c;
    }

    cout << sum << endl;
    return 0;
}