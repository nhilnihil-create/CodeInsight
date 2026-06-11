#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    int sum = 0;
    vector<int> A(N);
    vector<int> B(N);
    for (int i = 0; i < N; i++) {
        cin >> A.at(i); sum += A.at(i);
    }
    for (int i = 0; i < N; i++) cin >> B.at(i);
    sum += B.at(N-1);
    int ans = sum;
    for (int i = 0; i < N-1; i++) {
        sum = sum - A.at(N-1-i) + B.at(N-2-i);
        ans = max(ans, sum);
    }
    cout << ans << endl;
}