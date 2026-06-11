#include <bits/stdc++.h>
using namespace std;

void input(long &n, vector<long> &a) {
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
}

long div(long n) { // 整数が2で割り切れる回数
    long count = 0;
    while (n % 2 == 0) {
        n /= 2;
        count++;
    }
    return count;
}

int main() {
    long n; vector<long> a;
    input(n, a);

    long sum = 0;
    for (int i = 0; i < n; i++) { //各要素の2で割り切れる回数の総和
        sum += div(a[i]);
    }
    cout << sum << endl;
}