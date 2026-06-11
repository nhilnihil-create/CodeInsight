#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <iomanip>
#include <bitset>
#include <set>
#include <map>
#include <stdio.h>

#define rep(i,n) for (int i = 0; i < (n); i++)
#define FOR(i,a,b) for (int i=(a); i < (b); i++)
#define INF 100000000000
#define MOD 1000000007 //10^9+7
using namespace std;
using ll = long long;
using P = pair<int, int>;

// 負の数にも対応した % 演算
long long mod(long long val, long long m) {
    long long res = val % m;
    if (res < 0) res += m;
    return res;
}

int main()
{
    int n, m, k;
    cin >> n >> m;
    vector<int> a(m,0);

    rep(i,n) {
        cin >> k;
        rep(j,k) {
            int tmp;
            cin >> tmp;
            tmp--;
            a[tmp]++;
        }
    }

    int ans = 0;
    sort(a.begin(), a.end());
    if (a[m-1] != n) {
        cout << 0 << endl;
        return 0;
    }
    rep(i,m) {
        if (a[i] == a[m-1])
            ans++;
    }
    cout << ans << endl;
    return 0;
}
