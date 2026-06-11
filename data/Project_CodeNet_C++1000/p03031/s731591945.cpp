#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define MIN(a,b) ((a)>(b)? (b): (a))
#define MAX(a,b) ((a)<(b)? (b): (a))

const long long INF = 1LL << 60;
typedef unsigned long long ll;
const long long MOD = 1000000000 + 7;

int main() {
    int n, m;
    cin >> n >> m;
    int k;
    vector<int> mask(n, 0);
    rep(i, m) {
        cin >> k;
        rep(j, k) {
            int tmp;
            cin >> tmp;
            mask[i] |=(1<<tmp-1);
        }
    }
    vector<int> p(n);
    rep(i, m) {
        cin >> p[i];
    }
    int out = 0;
    for (int bit = 0; bit < (1 << n); ++bit) {
        bool flag = true;
        rep(i, m) {
            int tmp = bit & mask[i];
            if (__builtin_popcount(tmp)%2!=p[i]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            out++;
        }
    }
    cout << out << endl;
    return 0;
}