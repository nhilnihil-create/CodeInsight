#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<string> blue(N);
    for (int i = 0; i < N; i++) {
        cin >> blue.at(i);
    }
    int M;
    cin >> M;
    vector<string> red(M);
    for (int i = 0; i < M; i++) {
        cin >> red.at(i);
    }
    int max = 0;
    for (int i = 0; i < N; i++) {
        int count = 0;
        for (int j = 0; j < N; j++) {
            if (blue.at(i) == blue.at(j)) {
                count++;
            }
        }
        for (int j = 0; j < M; j++) {
            if (blue.at(i) == red.at(j)) {
                count--;
            }
        }
        if (max < count) {
            max = count;
        }
    }
    cout << max;
}