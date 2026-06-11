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
int gcd(int x, int y) { return (y ? gcd(y, x%y) : x); }
/* main */
int main(){
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];
    vector<int> gcdVec(N);
    gcdVec[N-1] = a[N-1];
    for (int i = N-2; i >= 0; i--) gcdVec[i] = gcd(gcdVec[i+1], a[i]);

    int ans = gcdVec[1];
    int g = a[0];
    for (int i = 1; i < N-1; i++) {
        ans = max(ans, gcd(g, gcdVec[i+1]));
        g = gcd(g, a[i]);
    }
    ans = max(ans, g);
    cout << ans << '\n';
}
