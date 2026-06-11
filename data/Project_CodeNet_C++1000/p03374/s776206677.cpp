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

ll x[100010], v[100010], a[100010], b[100010];

int main() {
    int n, i;
    ll c, ans = 0;
    cin >> n >> c;
    
    x[0] = 0;  v[0] = 0;
    for(i = 1; i <= n; i++) {
        cin >> x[i] >> v[i];
    } 
    x[n+1] = c;  v[n+1] = 0;
    
    for(i = 1; i <= n; i++) {
        a[i] = a[i-1] + v[i] - (x[i] - x[i-1]);
    }
    for(i = 1; i <= n; i++) {
        a[i] = max(a[i], a[i-1]);
    } 
    
    for(i = n; i >= 1; i--) {
        b[i] = b[i+1] + v[i] - (x[i+1] - x[i]);
    }  
    for(i = n; i >= 1; i--) {
        b[i] = max(b[i], b[i+1]);
    } 
    
    for(i = 1; i <= n; i++) {
        ans = max(ans, a[i]);
        ans = max(ans, a[i] - x[i] + b[i+1]);
        ans = max(ans, b[i]);
        ans = max(ans, b[i] - (c - x[i]) + a[i-1]);
    }
    
    cout << ans << endl;
    return 0;
}