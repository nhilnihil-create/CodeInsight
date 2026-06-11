#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1LL << 60;

int main() {
    int n; cin >> n;
    int num = 111;
    int x = 0;
    for (int i = 1; i <= 9; i++) {
        x = num * i;
        if (x - n >= 0) {
            break;
        }
    }
    cout << x << endl;
    return 0;
}