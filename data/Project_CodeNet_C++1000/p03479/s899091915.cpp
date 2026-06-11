#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define Sort(a) sort(a.begin(), a.end())
const int INF = 1<<30;
const ll MOD = 1000000007;

int main(void) {

    ll X, Y; cin >> X >> Y;

    ll x = X, y = Y, ans = 1;

    while (x * 2 <= y) {
        ans++;
        x *= 2;
    }

    cout << ans << endl;


    return 0;
}