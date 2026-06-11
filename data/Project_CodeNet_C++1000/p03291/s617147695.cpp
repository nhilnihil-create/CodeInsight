#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define lc 2 * v
#define rc 2 * v + 1
#define mid (s + e) / 2
#define ll long long
#define int long long
#define ld long double
#define pii pair <int , int>
#define pll pair <long long , long long>
#define FAST ios::sync_with_stdio(false);cin.tie(0);
// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")

const int maxn = 1e5 + 100 , N = 1e5 + 5 , SQ = 600 , base = 1999 , mod = 1e9 + 7 , INF = 1e18 , lg = 17;

int n , p2[maxn] , p1[maxn][5] , suma[maxn] , sumb[maxn] , sumc[maxn] , sumq[maxn] , ans;
string s;

// 0 -> B C , 1 -> ? C , 2 -> ? ? , 3 -> B ?;

inline void pre() {
    p2[0] = 1;
    for (int i = 1; i < maxn; ++i) {
        p2[i] = (p2[i - 1] * 3) % mod;
    }
    for (int j = n; j >= 1; --j) {
        suma[j] = suma[j + 1] + (s[j - 1] == 'A');
    }
    for (int j = n; j >= 1; --j) {
        sumb[j] = sumb[j + 1] + (s[j - 1] == 'B');
    }
    for (int j = n; j >= 1; --j) {
        sumc[j] = sumc[j + 1] + (s[j - 1] == 'C');
    }
    for (int j = n; j >= 1; --j) {
        sumq[j] = sumq[j + 1] + (s[j - 1] == '?');
    }

    for (int j = n; j >= 1; --j) {
        p1[j][0] = p1[j + 1][0];
        (p1[j][0] += (s[j - 1] == 'B' ? sumc[j + 1] : 0)) %= mod;
    }
    for (int j = n; j >= 1; --j) {
        p1[j][1] = p1[j + 1][1];
        (p1[j][1] += (s[j - 1] == '?' ? sumc[j + 1] : 0)) %= mod;
    }
    for (int j = n; j >= 1; --j) {
        p1[j][2] = p1[j + 1][2];
        (p1[j][2] += (s[j - 1] == '?' ? sumq[j + 1] : 0)) %= mod;
    }
    for (int j = n; j >= 1; --j) {
        p1[j][3] = p1[j + 1][3];
        (p1[j][3] += (s[j - 1] == 'B' ? sumq[j + 1] : 0)) % mod;
    }
}

int32_t main() {
    FAST
    cin >> s;
    n = s.size();
    pre();

    for (int i = n; i >= 1; --i) {
        if(s[i - 1] == 'A') {
            ans = (ans + (p1[i + 1][0] * p2[sumq[1]]) % mod) % mod;
            // cout << p1[i + 1][0] * p2[sumq[1]] << endl;
            ans = (ans + (p1[i + 1][1] * p2[sumq[1] - 1]) % mod) % mod;
            // cout << p1[i + 1][1] * p2[sumq[1] - 1] << endl;
            ans = (ans + (p1[i + 1][2] * p2[sumq[1] - 2]) % mod) % mod;
            // cout << p1[i + 1][2] * p2[sumq[1] - 2] << endl;
            ans = (ans + (p1[i + 1][3] * p2[sumq[1] - 1]) % mod) % mod;
            // cout << p1[i + 1][3] * p2[sumq[1] - 1] << endl;
            // cout << ans << endl;
        }
        else if(s[i - 1] == '?') {
            ans = (ans + (p1[i + 1][0] * p2[sumq[1] - 1]) % mod) % mod;
            ans = (ans + (p1[i + 1][1] * p2[sumq[1] - 2]) % mod) % mod;
            // cout << i << ' ' << p1[i + 1][1] << endl;
            ans = (ans + (p1[i + 1][2] * p2[sumq[1] - 3]) % mod) % mod;
            ans = (ans + (p1[i + 1][3] * p2[sumq[1] - 2]) % mod) % mod;
        }
        // cout <<  "hey" << ans << '\n';
    }

    cout << ans << '\n';
 }
