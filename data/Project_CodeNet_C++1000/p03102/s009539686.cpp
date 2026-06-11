#include<iostream>
using namespace std;

int main() {
    int N, M, C; cin >> N >> M >> C;
    int ans = 0;
    int B[M];
    for (int i = 0; i < M; i++) {
        cin >> B[i];
    }
    for (int i = 0; i < N; i++) {
        int A;
        int sum = 0;
        for (int j = 0; j < M; j++) {
            cin >> A;
            sum += A * B[j];
        }
        if (sum + C > 0) {
            ans++;
        }
    }
    cout << ans << endl;
}
