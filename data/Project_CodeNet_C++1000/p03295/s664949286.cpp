#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<iomanip>
#include<map>
#include<deque>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define erep(i, n) for (int i = 0; i <= (int)(n); i++)
using p = pair<int, int>;

int main() {
    int n, m; cin >> n >> m;
    vector<p> vec(m);
    rep (i, m) {
        int a, b; cin >> a >> b;
        vec[i].first = b;
        vec[i].second = a;
    }
    sort(vec.begin(), vec.end());

    int ans = 0;
    int cur = -10;
    rep (i, m) {
        if (vec[i].second < cur) continue;
        ans++;
        cur = vec[i].first;
    }
    cout << ans << endl;
}
