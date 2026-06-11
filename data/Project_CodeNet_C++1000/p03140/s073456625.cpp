#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n;
    string a, b, c;
    cin >> n >> a >> b >> c;

    int ans = 0;
    rep(i, n) {
        if(a[i] == b[i] && b[i] == c[i]) {
            continue;
        }
        else if(a[i] == b[i] || b[i] == c[i] || c[i] == a[i]) {
            ans++;
        }
        else {
            ans += 2;
        }
    }

    cout << ans << endl;
    return 0;
}