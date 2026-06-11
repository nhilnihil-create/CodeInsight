#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const long long INF = 1e15;

#include <math.h>
#define PI 3.14159265358979323846264338327950L

int mxN = 500000;
vector<int> cnt(mxN + 1);

int main() {
    int a, b;
    cin >> a >> b;
    if (a <= 5) {
        cout << 0;
    }
    else if (a <= 12) {
        cout << b / 2;
    }
    else {
        cout << b;
    }

    return 0;
}