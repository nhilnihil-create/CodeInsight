#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <map>
using namespace std;

#define INF 1e9
#define LLINF 1e18
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

int gcd(int a, int b) {
    if(a % b == 0) {
        return b;
    }
    else {
        return(gcd(b, a % b));
    }
}


int main() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    rep(i, n) cin >> a.at(i);
    a.push_back(x);
    sort(a.begin(), a.end());
    vector<int> dif(a.size() - 1);
    rep(i, dif.size()) {
        dif.at(i) = a.at(i + 1) - a.at(i);
    }
    int ans = dif.at(0);
/*    if (dif.size() == 2) {
        cout << dif.at(1) - dif.at(0) << endl;
        return 0;
    }*/
    for (int i = 1; i < dif.size(); i++) {
        ans = gcd(ans, dif.at(i));
    }
    cout << ans << endl;
}