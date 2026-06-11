#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
using namespace std;
int main() {
    int N, X;
    cin >> N >> X;
    int sum = 0;
    int sukunaiyatu = INT_MAX;
    for (int i=0; i < N; i++) {
        int n;
        cin >> n;
        sum += 1;
        X -= n;
        if (n < sukunaiyatu) {
            sukunaiyatu = n;
        }
    }

    sum += X / sukunaiyatu;
    cout << sum << endl;
    return 0;
}