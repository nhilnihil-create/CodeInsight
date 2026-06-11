#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1LL << 60;

int main() {
    int n, d, x; cin >> n >> d >> x;
    int choco = x;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        int j = 0;
        while (j * a + 1 <= d) {
            choco++;
            j++;
        }
    }
    cout << choco << endl;
    return 0;
}