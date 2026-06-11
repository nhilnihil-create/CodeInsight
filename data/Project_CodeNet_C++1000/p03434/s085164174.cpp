#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A.at(i);
    }

    sort(A.begin(), A.end(),greater<int>());

    int diff= 0;
    for (int i = 0; i < N; i++) {
        if (i % 2 == 0) {
            diff += A.at(i);
        }
        else {
            diff -= A.at(i);
        }
    }

    cout << diff << endl;
    return 0;
}