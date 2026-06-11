// Attention
#include <string>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, mi = 1 << 30;
    string S;
    cin >> N >> S;
    int W_sum[N] = {0}, E_sum[N] = {0};
    // W_sumは左，E_sumは右から累積和を取る
    for (int i = 0; i < N; i++) {
        if (S[i] == 'W') {
            if (i == 0) W_sum[i] = 1;
            else W_sum[i] = W_sum[i - 1] + 1;
        } else {
            if (i == 0) W_sum[i] = 0;
            else W_sum[i] = W_sum[i - 1];
        }
    }
    for (int i = 0; i < N; i++) {
        if (S[N - i - 1] == 'E') {
            if (i == 0) E_sum[N - 1] = 1;
            else E_sum[N - i - 1] = E_sum[N - i] + 1;
        } else {
            if (i == 0) E_sum[N - 1] = 0;
            else E_sum[N - i - 1] = E_sum[N - i];
        }
    }

    for (int i = 0; i < N; i++) {
        if (i == 0) {
            mi = min(mi, E_sum[1]);
        } else if (i == N - 1) {
            mi = min(mi, W_sum[N - 2]);
        } else {
            mi = min(mi, W_sum[i - 1] + E_sum[i + 1]);
        }
    }

    // cout << "---" << endl;
    // for (int i = 0; i < N; i++) cout << W_sum[i] << ' ';
    // cout << endl;
    // for (int i = 0; i < N; i++) cout << E_sum[i] << ' ';
    // cout << endl;
    // cout << "---" << endl;
    cout << mi << endl;
}