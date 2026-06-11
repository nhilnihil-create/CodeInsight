#include <iostream>
using namespace std;

int main() {
    int N, M, like[30] = { 0 }, count = 0;
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        int K;
        cin >> K;
        for (int j = 0; j < K; j++)
        {
            int A;
            cin >> A;
            like[A - 1]++;
        }
    }
    for (int i = 0; i < M; i++) if (like[i] == N) count++;
    cout << count;
}