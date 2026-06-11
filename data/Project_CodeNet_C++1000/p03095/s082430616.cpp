#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <map>
#include <queue>
#include <cassert>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define ALL(a) (a).begin(), (a).end()
#define rALL(a) (a).rbegin(), (a).rend()
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int iINF = 1001001001;
const long long llINF = 1LL << 60;
const ll mod = 1e9 + 7;
int main()
{
    // ARC031-A, 1014, 
    int n; string s; cin >> n >> s;
    map<char, int> mp;
    rep(i, 26) {
        char a = 'a' + i;
        mp[a] = 1;
    }
    rep(i, n) {
        mp[s[i]]++;
    }
    ll ans = 1;
    for (auto itr = mp.begin(); itr != mp.end(); ++itr) {
        ans *= ll((*itr).second);
        ans %= mod;
    }
    cout << ans - 1 << endl;

    return 0;
}