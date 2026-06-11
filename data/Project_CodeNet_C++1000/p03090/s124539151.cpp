#include <iostream>
using namespace std;

int main() {
    int N; cin >> N;
    int M = (N * (N - 2) + 1) / 2;

    cout << M << endl;
    for (int i = 1; i <= N - 1; i++) {
        for (int j = i + 1; j <= N; j++) {
            if (i + j != ((N & 1) ? N : N + 1))
                cout << i << " " << j << endl;
        }
    }
}