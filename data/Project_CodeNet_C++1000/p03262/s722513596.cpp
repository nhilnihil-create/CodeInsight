#include <bits/stdc++.h>
#include <iostream>
#include<math.h>
using namespace std;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
int64_t gcd(int64_t a, int64_t b) {
    if (b > a) {
        int64_t c = a;
        a = b;
        b = c;
    }

    if (a % b == 0) {
        return b;
    }

    int64_t c = a % b;
    return gcd(b, c);
}

int main()
{
    int64_t N, X;
    cin >> N >> X;
    vector<int64_t>vec(N);
    for (int64_t i=0; i<N; i++) {
        cin >> vec.at(i);
    }

    vector<int64_t>abs_(N);
    for (int64_t i=0; i<N; i++) {
        abs_[i] = abs(X - vec[i]);
    }

    int64_t num = abs_[0];
    for (int64_t i=1; i<N; i++) {
        num = gcd(num, abs_[i]);
    }

    cout << num << endl;
    return 0;
}