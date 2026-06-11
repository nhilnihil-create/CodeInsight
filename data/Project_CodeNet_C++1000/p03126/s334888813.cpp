#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    int N, M; cin >> N >> M;
    int data[M] = {0};
    fill_n(data, M, 0);
    for (int i = 0; i < N; i++) {
        int K; cin >> K;
        for (int j = 0; j < K; j++) {
            int A; cin >> A;
            data[A - 1]++;
        }
    }
    int ans = 0;
    for (int i = 0; i < M; i++) {
        if (data[i] == N) {
            ans++;
        }
    }
    cout << ans << endl;
}
