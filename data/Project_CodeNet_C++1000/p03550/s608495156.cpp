#include <bits/stdc++.h>
using namespace std;
template<class T, class U> inline bool chmax(T& a,U b) { if (a < b) { a = b; return 1; } return 0; }
template<class T, class U> inline bool chmin(T& a,U b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    int N, a, b;
    cin >> N >> a >> b;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    
    int ans = 0;
    if (N == 1) ans = abs(b - A[0]);
    else ans = max(abs(A[N-1] - b), abs(A[N-2] - A[N-1]));
    cout << ans << endl;
    return 0;
}