#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<vector<int>> group;
    for (int i = 1; i <= N / 2; i++) {
        vector<int> t;
        t.push_back(i);
        if (N % 2 == 0) {
            t.push_back(N + 1 - i);
        } else {
            t.push_back(N - i);
        }
        group.push_back(t);
    }
    if (N % 2 == 1) {
        vector<int> t;
        t.push_back(N);
        group.push_back(t);
    }

    if (N % 2 == 0) {
        cout << N * (N - 2) / 2 << endl;
    } else {
        cout << ((N - 1) * (N - 2) + (N - 1)) / 2 << endl;
    }

    for (int i = 0; i < group.size(); i++) {
        for (int j = i + 1; j < group.size(); j++) {
            for (int u : group[i]) {
                for (int v : group[j]) {
                    cout << u << " " << v << endl;
                }
            }
        }
    }
    return 0;
}
