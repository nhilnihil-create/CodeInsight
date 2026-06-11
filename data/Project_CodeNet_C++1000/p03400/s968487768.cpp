#include <bits/stdc++.h>
using namespace std;

int main() {
    int N,D,X;
    cin >> N >> D >> X;
    vector<int>A(N);
    int ans = X;
    for(int i = 0; i < N; i++) {
        cin >> A[i];
        ans++;
        ans+=(D-1)/A[i];
    }
    cout << ans << endl;
}
