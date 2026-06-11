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

#define ll int64_t
#define Rep(i, n) for (ll i = 0; i < n; i++)
using namespace std;
typedef vector<ll> vec;
typedef vector<vec> mat;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll K;
    cin >> K;
    vec A(K);
    Rep (i, K) {
        cin >> A[i];
    }
    reverse(A.begin(), A.end());

    ll L = 2, R = 2;
    Rep (i, K) {
        ll l = L, r = R;
        L = (l + A[i] - 1) / A[i] * A[i];
        R = r / A[i] * A[i] + A[i] - 1;
        if (L > R) {
            cout << "-1\n";
            return 0;
        }
    }

    cout << L << " " << R << "\n";
}