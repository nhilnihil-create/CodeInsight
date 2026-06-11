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
    string S;
    ll K;
    cin >> S >> K;
    int cnt1 = 0;
    char ans;
    for (int i = 0; i < S.size(); i++) {
        if (S[i] == '1') cnt1++;
        else {
            ans = S[i];
            break;
        }
    }
    if (K <= cnt1) cout << 1 << '\n';
    else cout << ans << '\n';
}
