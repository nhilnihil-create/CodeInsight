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
    int n, a, b;
    cin >> n >> a >> b;

    int cnt1 = 0, cnt2 = 0, cnt3 =0;
    rep(i, n) {
        int p;
        cin >> p;
        if(p <= a) {
            cnt1++;
        }
        else if(p <= b) {
            cnt2++;
        }
        else {
            cnt3++;
        }
    }

    int ans = min({cnt1, cnt2, cnt3});

    cout << ans << endl;
    return 0;
}