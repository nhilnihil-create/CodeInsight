#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <iomanip>
#include <cstdio>
#include <set>
#include <map>
#include <list>
#include <cstdlib>

using namespace std;

#define mod (1e9 + 7)
#define rep(i, n) for (int i = 0; i < n; i++)
#define all(x) x.begin(), x.end()

typedef long long ll;

void solve1()
{
    ll n, h, w; cin >> n >> h >> w;
    vector<ll> a(n), b(n);
    rep(i, n) {
        cin >> a[i] >> b[i];
    }

    int cnt = 0;
    rep(i, n) {
        if(a[i] >= h && b[i] >= w) {
            cnt ++;
        }
    }

    cout << cnt << endl;

}

int main()
{
    solve1();
}
