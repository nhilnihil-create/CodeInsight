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

ll ceil(ll a, ll b) {  // a÷b以上の最小の整数

    if(b == 0) {
        return 0;  // 0除算エラーを防ぐ
    }

    if(a%b == 0) {
        return a/b;
    }
    else {
        return a/b + 1LL;
    }
}

int main() {
    int k;
    cin >> k;

    vector<ll> a(k+1);
    for(int i = 1; i <= k; i++) {
        cin >> a[i];
    }
    
    vector<ll> L(k+1), R(k+1);
    L[k] = R[k] = 2LL;
    
    for(int i = k; i >= 1; i--) {
        ll y = (R[i]/a[i])*a[i];
        if(y < L[i]) {
            cout << -1 << endl;
            return 0;
        }
        L[i-1] = ceil(L[i], a[i])*a[i];
        R[i-1] = y + a[i] - 1;
    }

    cout << L[0] << " " << R[0] << endl;
    return 0;
}