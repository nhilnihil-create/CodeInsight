#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1LL << 60;
const int MAX = 1000000010;
const ll MOD = 1000000007;

int main() {
    int A, B, C; cin >> A >> B >> C;
    if (A == B) {
        cout << C << endl;
    } else if (B == C) {
        cout << A << endl;
    } else {
        cout << B << endl;
    }

    return 0;
}