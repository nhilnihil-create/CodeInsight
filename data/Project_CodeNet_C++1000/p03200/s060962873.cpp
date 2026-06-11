#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <set>
#include <cassert>
#include <random>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;
typedef long long int ll;
const ll INF = 10000000000;
const double PI = acos(-1);
const ll mod = 1000000007;

int main()
{
    string s;
    cin >> s;

    ll ans = 0;
    ll cnt = 0;
    rep(i, s.size()) {
        if (s[s.size() - 1 - i] == 'B') {
            ans += i - cnt;
            cnt++;
        }
    }
    cout << ans << endl;
    return 0;
}
