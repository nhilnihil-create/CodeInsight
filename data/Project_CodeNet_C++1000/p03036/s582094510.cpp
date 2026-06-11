#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const long long INF = 1e15;

#include <math.h>
#define PI 3.14159265358979323846264338327950L

int mxN = 500000;
vector<int> cnt(mxN + 1);

int main() {
    int r, D, y;
    cin >> r >> D >> y;
    vector<int> x(11);
    x[0] = y;
    for (int i = 1; i < 11; i++) {
        x[i] = r * x[i - 1] - D;
        cout << x[i] << "\n";
    }

    return 0;
}