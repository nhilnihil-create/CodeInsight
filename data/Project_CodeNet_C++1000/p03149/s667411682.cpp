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

    vector<int> N(4);
    rep(i, 4) {
        cin >> N[i];
    }
    sort(N.begin(), N.end());

    int x[4] = {1, 4, 7, 9};

    rep(i, 4) {
        if(N[i] != x[i]) {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
    return 0;
}