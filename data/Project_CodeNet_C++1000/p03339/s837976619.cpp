#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    string S;
    cin >> N >> S;
    vector<int> sum(N);
    int ans = INFINITY;
    int count = 0;
    for (int i = 0; i < N; i++) {
        if (S.at(i) == 'W') count++;
        sum.at(i) = count;
    }
    for (int i = 0; i < N; i++) {
        int ans_i;
        if (i == 0) ans_i =(N - 1 - i) - sum.at(N - 1) + sum.at(i);
        else if (i == N - 1) ans_i = sum.at(i - 1);
        else ans_i = sum.at(i - 1) + (N - 1 - i) - sum.at(N - 1) + sum.at(i);
        ans = min(ans, ans_i);
    }
    cout << ans << endl;
}