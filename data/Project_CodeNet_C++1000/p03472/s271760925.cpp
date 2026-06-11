#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    long long N, M; cin >> N >> M;
    vector<long long>A(N), B(N);
    for (long long i = 0; i < N; i++) {
        cin >> A.at(i) >> B.at(i);
    }
    sort(A.begin(), A.end(), greater<long long>());
    sort(B.begin(), B.end(), greater<long long>());
    long long ans = 0;
    for (long long i = 0; i < N; i++) {
        if (B.at(i) > A.at(0)) {
            M -= B.at(i);
            ans++;
        }
        if (M <= 0) {
            cout << ans << endl;
            return 0;
        }
    }
    ans += M / A.at(0);
    if (M % A.at(0) != 0) ans++;
    cout << ans << endl;
}