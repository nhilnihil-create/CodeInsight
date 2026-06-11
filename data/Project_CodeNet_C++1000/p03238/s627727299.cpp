#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1LL << 60;

int main() {
    int n; cin >> n;
    if (n == 1) {
        cout << "Hello World" << endl;
    } else {
        int a, b; cin >> a >> b;
        cout << a + b << endl;
    }
    return 0;
}