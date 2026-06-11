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
    int N;
    cin >> N;
    vector<pii> v(N+1);
    vector<int> t(N+1);
    v[0] = pii(0, 0);
    t[0] = 0;
    for (int i = 1; i <= N; i++) {
        int x, y;
        cin >> t[i] >> x >> y;
        v[i] = pii(x, y);
    }
    bool can = true;
    for (int i = 0; i < N; i++) {
        int dt = t[i+1] - t[i];
        int d = abs(v[i].first - v[i+1].first) + abs(v[i].second - v[i+1].second);
        if (d > dt || (d % 2 != dt % 2)) can = false;
    }
    cout << (can ? "Yes" : "No") << '\n';
}
