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
const int mod = 1000000007;
const double pi = 3.141592653589;
/* global variables */
/* function */
/* main */
int main(){
    int X;
    cin >> X;
    int mx = 1;
    for (int i = 2; i * i <= X; i++) {
        int k = i * i;
        for (; k <= X; k *= i) {
            mx = max(mx, k);
        }
    }
    cout << mx << '\n';
}
