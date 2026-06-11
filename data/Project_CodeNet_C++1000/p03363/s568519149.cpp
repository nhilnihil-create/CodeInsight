#include <bits/stdc++.h>

#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;

    map<ll, ll> acc_sum;
    ll sum = 0;
    for (int i = 0; i < N; i++) {
        ll A;
        cin >> A;
        sum += A;
        acc_sum[sum]++;
    }

    ll output = 0;
    for (auto e : acc_sum) {
        // cout << e.first << " " << e.second << endl;
        if (e.first == 0) {
            output += e.second * (e.second + 1) / 2;
            continue;
        }
        if (e.second != 1) {
            output += e.second * (e.second - 1) / 2;
        }
    }
    cout << output << endl;

    return 0;
}
