#include <bits/stdc++.h>
using namespace std;
/* typedef */
typedef long long ll;
typedef pair<int, int> pii;
/* constant */
const int INF = 1 << 30;
const ll LINF = 1LL << 61;
const int NIL = -1;
const int MAX = 10000;
const int MOD = 1000000007;
const double pi = 3.141592653589;
/* global variables */
/* function */
/* main */
int main(){
    int n;
    cin >> n;
    vector<int> L(n);
    for (int &l : L) cin >> l;
    int ans = pow(3, n);
    int only_odd = 1;
    for (int i = 0; i < n; i++) {
        only_odd *= (L[i] % 2) ? 1 : 2;
    }
    cout << ans - only_odd << '\n';
}
