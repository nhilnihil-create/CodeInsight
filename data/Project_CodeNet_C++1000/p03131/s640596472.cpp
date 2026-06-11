#include <bits/stdc++.h>
using namespace std;
/* typedef */
typedef long long ll;
typedef pair<int, int> pii;
/* constant */
const int INF = 1 << 30;
const ll LINF = 1LL << 50;
const int NIL = -1;
const int MAX = 10000;
const int mod = 1000000007;
const double pi = 3.141592653589;
/* global variables */
/* function */
/* main */
int main(){
    ll K, A, B;
    cin >> K >> A >> B;
    // K回叩く
    ll a1 = 1 + K;

    // A - 1times punch
    K = max(0LL, K - (A-1));
    // A -> 1yen -> B -> 1yen ...
    ll a2 = A + (K / 2) * (B - A) + (K % 2);
    cout << max(a1, a2) << '\n';
}
