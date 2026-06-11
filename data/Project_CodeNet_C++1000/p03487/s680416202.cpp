#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<vector<int>> Graph;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
#define pi 3.14159265359
#define inf 2147483647
#define INF 9223372036854775807
#define mod 1000000007
#define mod2 998244353

int main() {
    int N; cin >> N;
    map<int, int> cnt;
    for(int i = 0; i < N; i++) {
        int a; cin >> a;
        if(!cnt.count(a)) cnt[a] = 1;
        else cnt[a]++;
    }
    ll ans = 0;
    for(auto p: cnt) {
        if(p.first < p.second) ans += p.second - p.first;
        else if(p.first > p.second) ans += p.second;
    }
    cout << ans << endl;
    return 0;
}