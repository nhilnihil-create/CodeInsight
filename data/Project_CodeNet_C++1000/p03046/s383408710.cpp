#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <algorithm>
#include <cstdio>
#include <iomanip>
#include <queue>
#include <deque>
#include <stack>
#include <fstream>
#include <cmath>
#include <random>

#define ll int64_t
#define Rep(i, n) for (ll i = 0; i < n; i++)
using namespace std;
typedef vector<ll> vec;
typedef vector<vec> mat;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll M, K;
    cin >> M >> K;

    if (M == 0) {
        if (K == 0) {
            cout << "0 0\n";
        } else {
            cout << "-1\n";
        }
        return 0;
    } else if (M == 1) {
        if (K == 0) {
            cout << "0 0 1 1\n";
        } else {
            cout << "-1\n";
        }
        return 0;
    }

    if (K >= 1<<M) {
        cout << "-1\n";
        return 0;
    }

    vec ans;
    Rep (i, 1<<M) {
        if (i == K) continue;
        ans.push_back(i);
    }
    ans.push_back(K);
    for (ll i = (1<<M) - 1; i >= 0; i--) {
        if (i == K) continue;
        ans.push_back(i);
    }
    ans.push_back(K);

    Rep (i, 1<<(M+1)) {
        cout << ans[i] << " \n"[i==(1<<(M+1))-1];
    }
}