#include <bits/stdc++.h>
using namespace std;

#define rp(i, k, n) for (int i = k; i < n; i++)
typedef long long ll;
typedef double ld;

template<class T>inline bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>inline bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF = 1ll << 60;
const ll MOD = 1e9 + 7ll;
const double PI=3.14159265358979323846;


int main() {
    int m, k;
    cin >> m >> k;
    m = (1<<m);
    if(k == 0) {
        rp(i, 0, m) {
            printf("%d %d ", i, i);
        }
        printf("\n");
        return 0;
    }
    if(k >= m || (k == 1 && m == 2)) {
        cout << -1 << endl;
        return 0;
    }
    rp(i, 0, m) {
        if(i != k) printf("%d ", i);
    }
    printf("%d ", k);
    for(int i = m-1; i >= 0; i--) {
        if(i != k) printf("%d ", i);
    }
    printf("%d\n", k);
    return 0;
}