#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, x, y;
    cin >> N;
    vector<pair<int, int>> R(N), B(N);
    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        R[i] = make_pair(x, y);
    }
    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        B[i] = make_pair(x, y);
    }
    
    sort(R.begin(), R.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
        if (a.second != b.second) {
            return a.second > b.second;
        }
        else {
            return a.first > b.first;
        }
    });

    sort(B.begin(), B.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
        if (a.first != b.first) {
            return a.first < b.first;
        }
        else {
            return a.second < b.second;
        }
    });

    int C = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (R[j].first < B[i].first && R[j].second < B[i].second) {
                R[j].second = 2*N;
                C++;
                break;
            }
        }
    }
    cout << C << endl;
}
