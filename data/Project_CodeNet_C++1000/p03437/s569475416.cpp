#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1000000007;



int main() {
    long long A, B;
    cin >> A >> B;
    if (A % B == 0)cout << -1;
    else cout << A * (B - 1);
}