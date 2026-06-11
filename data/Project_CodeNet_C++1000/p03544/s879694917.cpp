#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int64_t> L(N+1);

    L.at(0) = 2;
    L.at(1) = 1;
    for (int i = 2; i<=N; i++) {
        L.at(i) = L.at(i-1) + L.at(i-2);
    }
    cout << L.at(N);
    return 0;
}