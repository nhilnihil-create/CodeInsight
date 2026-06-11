#include <bits/stdc++.h>
#include <iostream>

using namespace std;

typedef long long ll;

int main() {
    int N;
    cin >> N;
    ll m = 999999999999999;
    for (int i = 0; i < N; i++) {
        int A;
        cin >> A;
        ll cnt = 0;
        while (A % 2 == 0) {
            A /= 2;
            cnt++;
        }
        m = min(m, cnt);
    }

    cout << m << endl;
}