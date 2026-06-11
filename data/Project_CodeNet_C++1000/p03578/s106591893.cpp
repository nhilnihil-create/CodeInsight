#include <bits/stdc++.h>
using namespace std;
typedef long long Int;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n; cin >> n;
    //vector<int> d(n);
    map<int, int> d;
    rep(i, n) {
        int tmp; cin >> tmp;
        d[tmp]++;
    }
    int m; cin >> m;
    vector<int> t(m);
    rep(i, m) {
        int tmp; cin >> tmp;
        if (d[tmp] == 0) {
            puts("NO");
            return 0;
        }
        d[tmp]--;
    }
    puts("YES");
}