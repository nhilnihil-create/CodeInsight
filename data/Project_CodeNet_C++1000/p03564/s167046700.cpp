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
    int n, k;
    cin >> n >> k;
    int mi = INF;
    for (int i = 0; i <= n; i++) {
        int tmp = 1;
        for (int j = 0; j < i; j++) tmp *= 2;
        for (int j = 0; j < n - i; j++) tmp += k;
        mi = min(mi, tmp);
    }
    cout << mi << '\n';
}
