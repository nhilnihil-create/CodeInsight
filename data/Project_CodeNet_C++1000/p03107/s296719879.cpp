#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;

int gcd(int a, int b) {
    if(a % b == 0) {
        return b;
    } else {
        return gcd(b, a % b);
    }
}



int main() {
    string S;
    cin >> S;
    int zero_count = count(S.begin(), S.end(), '0');
    int one_count = count(S.begin(), S.end(), '1');

    int m = min(zero_count, one_count);
    cout << m * 2 << endl;
}