#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int calcDigitSum(int a, int b) {
    int digitSum = 0;

    while (a) {
        digitSum += a % 10;
        a /= 10;
    }
    while (b) {
        digitSum += b % 10;
        b /= 10;
    }
    return digitSum;
}


int main() {
    int n;
    cin >> n;

    int digitSum = 100000;
    for (int i = 1; i < n ; ++i) {
        int j = n - i;
        if (digitSum > calcDigitSum(i, j)) {
            digitSum = calcDigitSum(i, j);
        }
    }
    cout << digitSum << endl;
    return 0;
}
