#include<iostream>
using namespace std;

int main() {
    int N; cin >> N;
    string W[N];
    bool heObeyRule = true;
    for (int i = 0; i < N; i++) {
        cin >> W[i];
    }
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            if (W[i] == W[j]) {
                heObeyRule = false;
            }
        }
        if (W[i][W[i].size() - 1] != W[i + 1][0]) {
            heObeyRule = false;
        }
    }
    if (heObeyRule) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
