#include <bits/stdc++.h>
using namespace std;
/* typedef */
typedef long long ll;
typedef pair<int, int> pii;
/* constant */
const int INF = 1 << 30;
const ll LINF = 1LL << 50;
const int NIL = -1;
const int MAX = 10000;
const int mod = 1000000007;
const double pi = 3.141592653589;
/* global variables */
map<int, int> factor;
/* function */
void primeFactrization(int n) {
    int x = n;
    if (x < 2) {
        return ;
    }
    for (int i = 2; i * i <= n; i++) {
        while (x % i == 0) {
            factor[i]++;
            x /= i;
        }
    }
    if (x != 1) { factor[x]++; }
}
/* main */
int main(){
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) { primeFactrization(i); }

    int ans = 0;
    vector<int> nums{74, 24, 14, 4, 2,};
    map<int, int> cnt;
    for (int n : nums) {
        for (auto f : factor)
            if (f.second >= n) cnt[n]++;
    }
    ans += cnt[74];
    ans += cnt[14] * (cnt[4] - 1);
    ans += cnt[24] * (cnt[2] - 1);
    ans += cnt[4] * (cnt[4] - 1) / 2 * (cnt[2] - 2);
    cout << ans << '\n';
}