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

const int N_MAX = 3010;



int main() {
    int n; cin >> n;
    int now_x = 0;
    int now_y = 0;
    int now_t = 0;
    rp(i, 0, n) {
        int x, y, t;
        cin >> t >> x >> y;
        int time = (t - now_t) - abs(x - now_x) - abs(y - now_y);
        if(time < 0 || time%2 == 1) {
            cout << "No" << endl;
            return 0;
        }
        now_x = x;
        now_y = y;
        now_t = t;
    }
    cout << "Yes" << endl;
    return 0;
}