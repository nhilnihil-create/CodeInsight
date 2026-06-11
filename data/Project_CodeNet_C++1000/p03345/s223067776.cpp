#include <bits/stdc++.h>
#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int64_t A, B, C, K;
    int64_t max_val = pow(10, 18);
    cin >> A >> B >> C >> K;
    int64_t cnt = 0;

    if (abs(A - B) > max_val) {
        cout << "Unfair" << endl;
        return 0;
    }

    int64_t x = A - B;
    int64_t ans = 0;
    if (K % 2 == 0) {
        cout << x << endl;
    } else {
        cout << -1 * x << endl;
    }

    return 0;
}