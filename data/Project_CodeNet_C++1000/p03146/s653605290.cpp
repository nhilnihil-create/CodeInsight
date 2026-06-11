#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    map<int, int>d;
    d[N] = 1;
    int b_a = N;
    int num = 2;
    while (true) {
        int ans;
        if (b_a % 2 == 0) {
            ans = b_a /2;
        } else {
            ans = (3 * b_a) + 1;
        }

        if (d.count(ans) > 0) {
            break;
        } else {
            d[ans] = num;
        }

        b_a = ans;
        num++;
    }

    cout << num << endl;
    return 0;
}