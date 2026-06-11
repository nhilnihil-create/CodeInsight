#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
using namespace std;
int main() {
    string S;
    cin >> S;
    int64_t size = S.size();
    int64_t siro_count = 0;
    int64_t kuro_count = 0;
    for (int64_t i=0; i<size; i++) {
        if (i % 2 == 0) {
            if (S[i] == '0') {
                siro_count += 1;
            } else {
                kuro_count += 1;
            }
        } else {
            if (S[i] == '0') {
                kuro_count += 1;
            } else {
                siro_count += 1;
            }
        }
    }

    cout << min(siro_count, kuro_count) << endl;
    return 0;
}