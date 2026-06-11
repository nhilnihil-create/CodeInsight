#include <iostream>
#include <algorithm>
#include <string>
#define flush fflush(stdout)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, int> Pl;
const int mod = (int)1e9 + 7, INF = (int)1e9;
const int di[4] = { 1,0,-1,0 }, dj[4] = { 0,1,0,-1 };


int main(void) {
    int n, i, ra[100003] = {}, rc[100003] = {}, rht1[100003] = {}, rht2[100003] = {}, ans;
    string s;
    ll pa, pc, pow3[100003] = {};

    cin >> s;

    n = s.size();

    pow3[0] = 1;
    for (i = 0; i < n; i++) {
        pow3[i + 1] = pow3[i] * 3 % mod;
    }

    for (i = 0; i < n; i++) {
        if (s[i] == 'A') {
            ra[i + 1] = 1;
        }
        if (s[i] == 'C') {
            rc[i + 1] = 1;
        }
        if (s[i] == '?') {
            rht1[i + 1] = rht2[i + 1] = 1;
        }
    }

    for (i = 1; i <= n + 1; i++) {
        ra[i] += ra[i - 1];
        rht1[i] += rht1[i - 1];
    }
    for (i = n + 1; i >= 0; i--) {
        rc[i] += rc[i + 1];
        rht2[i] += rht2[i + 1];
    }

    ans = 0;
    for (i = 0; i < n; i++) {
        if (s[i] == 'B' || s[i] == '?') {
            pa = ((ll)ra[i] * pow3[rht1[i]] % mod + (ll)rht1[i] * pow3[max(0, rht1[i] - 1)] % mod) % mod;
            pc = ((ll)rc[i + 2] * pow3[rht2[i + 2]] % mod + (ll)rht2[i + 2] * pow3[max(0, rht2[i + 2] - 1)] % mod) % mod;
            ans = (ans + pa * pc % mod) % mod;
        }
    }

    printf("%d\n", ans);

    return 0;
}