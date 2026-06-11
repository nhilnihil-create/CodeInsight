#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A1(N),A2(N);
    for (int i = 0; i < N; i++) cin >> A1.at(i);
    for (int i = 0; i < N; i++) cin >> A2.at(i);
    int ans = 0;

    for (int i = 0; i < N; i++) {
        int sum = 0;
        for (int j = 0; j < i + 1; j++) sum += A1.at(j);
        for (int j = i; j < N; j++) sum += A2.at(j);
        ans = max(sum, ans);
    }
    cout << ans << endl;
}