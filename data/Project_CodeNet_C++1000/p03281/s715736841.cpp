#include <bits/stdc++.h>
using namespace std;

vector<long long> divisor(long long n) {
    vector<long long> ret;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ret.push_back(i);
            if (i * i != n) ret.push_back(n / i);
        }
    }
    return ret;
}

int main() {
    //
    int num;
    int kekka = 0;
    int cnt = 0;
    cin >> num;

    for (int i = 105; i <= num; i+= 2) {
        cnt = 0;
        for (int j = 1; j <= i; j++) {
            if (i % j == 0) cnt++;
        }

        if (cnt >= 8) kekka++;
    }
    
    cout << kekka;
}