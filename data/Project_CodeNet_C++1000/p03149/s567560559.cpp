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

    vector<int> a(4), b(4);
    rep(i, 4) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    b[0] = 1;
    b[1] = 4;
    b[2] = 7;
    b[3] = 9;

    rep(i, 4) {
        if(a[i] != b[i]) {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
    return 0;
}