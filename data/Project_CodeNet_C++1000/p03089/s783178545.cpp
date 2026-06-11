#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;

    vector<int> b(N);
    for (int i = 0; i < N; i++) {
        cin >> b[i];
    }

    vector<int> output;
    for (int i = N - 1; i >= 0; i--) {
        bool found = false;
        for (int j = i; j >= 0; j--) {
            if (b[j] == j + 1) {
                output.push_back(j + 1);
                found = true;
                b.erase(b.begin() + j);
                break;
            }
        }
        if (!found) {
            cout << -1 << endl;
            return 0;
        }
    }

    for (int i = 0; i < N; i++) {
        cout << output[N - i - 1] << endl;
    }

    return 0;
}
