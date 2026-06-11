#include <bits/stdc++.h>
using namespace std;
#define MAX 1000000

int main() {
    int N, D, x, cnt = 0;
    cin >> N >> D >> x;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A.at(i);
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j * A.at(i) + 1 <= D; j++) {
            cnt += 1;
        }
    }
    cout << cnt + x << endl;
}