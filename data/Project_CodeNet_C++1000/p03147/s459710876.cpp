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
    int n;
    int ans = 0;
    cin >> n;
    vector<int> h(n + 1, 0);
    for (int i = 1; i < n + 1; i++) cin >> h.at(i);
    rep(i, n) {
        if (h.at(i + 1) > h.at(i)) {
            ans += h.at(i + 1) - h.at(i);
        }
    }
    cout << ans << endl;
}