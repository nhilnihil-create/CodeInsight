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
    int N, a;
    cin >> N;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        cin >> a;
        while (a % 2 == 0) {
            a /= 2;
            ans++;
        }
    }
    cout << ans << '\n';
}
