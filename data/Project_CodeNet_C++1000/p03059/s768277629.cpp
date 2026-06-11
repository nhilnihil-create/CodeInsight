#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;

int main() {
    double a, b, t,index=1;
    cin >> a >> b >> t;

    while (1) {
        if ((index * a) < (t + 0.5))index++;
        else break;
    }
    cout << --index * b << endl;
    return 0;
}