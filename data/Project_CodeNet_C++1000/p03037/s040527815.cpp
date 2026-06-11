#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
using namespace std;
typedef long long ll;
typedef pair<int, int> pair;
const int inf = 1000000000; //10^9

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> l(m);
    vector<int> r(m);
    rep(i, m) {
        cin >> l[i];
        cin >> r[i];
    }

    int ml = 0, mr = inf;
    rep(i, m) {
        ml = max(ml, l[i]);
        mr = min(mr, r[i]);
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (ml <= i && mr >= i) ans++;
    }

    cout << ans << endl;

    return 0;
}