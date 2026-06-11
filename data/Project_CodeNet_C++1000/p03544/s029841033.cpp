#include <bits/stdc++.h>
using namespace std;
long long lucas(long long n) {
    long long l[n + 1];
    l[0] = 2;
    l[1] = 1;
    for (long long i = 2; i <= n; i++) l[i] = l[i - 1] + l[i - 2];
    return l[n];
}
int main() {
    long long n;
    cin >> n;
    cout << lucas(n);
}