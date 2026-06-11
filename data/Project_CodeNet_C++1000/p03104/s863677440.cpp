#include <bits/stdc++.h>
using namespace std;
/* typedef */
typedef long long ll;
typedef pair<int, int> pii;
/* constant */
const int INF = 1 << 30;
const ll LINF = 1LL << 50;
const int NIL = -1;
const ll MAX = 1e+12 + 1;
const int mod = 1000000007;
const double pi = 3.141592653589;
/* global variables */
/* function */
ll g(ll x) {
    ll ans = ((x + 1) / 2 ) % 2;
    ans ^= ((x + 1) % 2) * x;
    return ans;
}
/* main */
int main(){
    ll A, B;
    cin >> A >> B;
    cout << (g(B) ^ g(A - 1)) << '\n';
}
