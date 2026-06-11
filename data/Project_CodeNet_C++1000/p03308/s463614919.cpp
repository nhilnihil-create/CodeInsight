#include<iostream>
using namespace std;

int main() {
    int N; cin >> N;
    int A[N];
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    int ans = 0;
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            ans = max(ans, abs(A[i] - A[j]));
        }
    }
    cout << ans << endl;
}
