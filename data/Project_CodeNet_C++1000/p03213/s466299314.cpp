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
map<int, int> cnt;

void prime_factorize(int n) {
    vector<pair<int, int> > res;
    for (ll p = 2; p * p <= n; p++) {
        if (n % p != 0) continue;
        int num = 0;
        while (n % p == 0) { ++num; n /= p; }
        res.push_back(make_pair(p, num));
    }
    if (n != 1) res.push_back(make_pair(n, 1));
    for (auto v : res) cnt[v.first] += v.second;
}

int main() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) prime_factorize(i);
    int over_2 = 0;
    int over_4 = 0;
    int over_14 = 0;
    int over_24 = 0;
    int over_74 = 0;
    int ans = 0;
    for (auto v : cnt) {
        if (v.second >= 2) over_2++;
        if (v.second >= 4) over_4++;
        if (v.second >= 14) over_14++;
        if (v.second >= 24) over_24++;
        if (v.second >= 74) over_74++;
    }
    ans += over_4 * (over_4 - 1) / 2 * (over_2 - 2);
    ans += over_14 * (over_4 - 1); 
    ans += over_24 * (over_2 - 1); 
    ans += over_74;
    cout << ans << endl;
}
