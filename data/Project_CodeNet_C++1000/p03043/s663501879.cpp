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
    int N, K;
    cin >> N >> K;

    map<int, int> mp;
    for (int i = 1; i <= N; i++) {
        int m = max(0.0, ceil(log2(K) - log2(i)));
        mp[m]++;
    }
    double ans = 0;
    for (auto q : mp) {
        ans += pow(0.5, q.first) * q.second;
    }
    ans /= N;
    cout << fixed << setprecision(9) << ans << '\n';
}
