#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
using namespace std;
int main() {
    int A, B, C, D, E;
    cin >> A >> B >> C >> D >> E;
    int a_ = A % 10 > 0 ? 10 - (A % 10) : 0;
    int b_ = B % 10 > 0 ? 10 - (B % 10) : 0;
    int c_ = C % 10 > 0 ? 10 - (C % 10) : 0;
    int d_ = D % 10 > 0 ? 10 - (D % 10) : 0;
    int e_ = E % 10 > 0 ? 10 - (E % 10) : 0;
    cout << A + B + C + D + E + a_ + b_ + c_ + d_ + e_ - max({a_, b_, c_, d_, e_}) << endl;
    return 0;
}