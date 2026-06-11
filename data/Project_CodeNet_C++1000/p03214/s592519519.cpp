#include <bits/stdc++.h>
using namespace std;
int main () {
    int N;
    cin >> N;
    int S = 0;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        S += a[i];
    }
    int k = INT_MAX;
    for (int i = 0; i < N; i++) {
        k = min(k, abs(S-a[i]*N));
    }
    for (int i = 0; i < N; i++) {
        if (abs(S-a[i]*N) == k) {
            cout << i << endl;
            return 0;
        }
    }
}