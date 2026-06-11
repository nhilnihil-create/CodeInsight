#include <bits/stdc++.h>
#include <iostream>
#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
using namespace std;
int main() {
    int D, N;
    cin >> D >> N;
    int n = pow(100, D);
    if (N == 100) {
        N += 1;
    }

    int ans = n * N;
    cout << ans << endl;
    return 0;
}