#include <algorithm>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
#define rep(i, n) for(int(i) = 0; (i) < (n); (i)++)
#define FOR(i, m, n) for(int(i) = (m); (i) < (n); (i)++)
#define All(v) (v).begin(), (v).end()
#define pb push_back
#define MP(a, b) make_pair((a), (b))
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int INF = 1 << 30;
const ll LINF = 1LL << 60;
const int MOD = 1e9 + 7;

int next2(int a) {
    int ret = 1;
    while(ret <= a) {
        ret *= 2;
    }
    return ret;
}

int main() {
    int N;
    cin >> N;
    vector<int> power;
    int p = 1;
    vector<int> A(N);
    rep(i, N) cin >> A[i];
    sort(All(A));
    map<int, int> mp;
    rep(i, N) { mp[A[i]]++; }
    int res = 0;
    for(int i = N - 1; i >= 0; i--) {
        if(mp[A[i]] > 0) {
            mp[A[i]]--;
            int n = next2(A[i]);
            int s = n - A[i];
            if(mp[s] > 0) {
                mp[s]--;
                res++;
            }
        }
    }
    cout << res << endl;
    return 0;
}