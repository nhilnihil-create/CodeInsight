/**
 *    author:  Taichicchi
 *    created: 21.09.2020 22:45:50
 **/

#include <bits/stdc++.h>

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    if ((a < c) & (b > c)) {
        cout << "Yes" << endl;
    } else if ((a > c) & (b < c)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}