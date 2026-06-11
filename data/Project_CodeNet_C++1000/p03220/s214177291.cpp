#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, T, A;
    cin >> N >> T >> A;
    vector<int> data(N);
    for (int i = 0; i < N; i++) {
        cin >> data.at(i);
    }
    double min = 10e6, diff;
    int num;

    for (int i = 0; i < N; i++) {
        diff = abs(T - data.at(i) * 0.006 - A);
        if (min > diff) {
            min = diff;
            num = i + 1;
        }
    }
    cout << num << endl;
}
