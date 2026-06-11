#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1000000007;


int main() {
    int A, B, C,K;
    cin >> A >> B >> C>>K;
    int U = max(A,max( B, C));
    int ans = -U+A+B+C;
    U *= pow(2, K);
    ans += U;
    cout << ans;
}