#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <map>
#include <set>
using namespace std;
#define ll long long
#define rep(i, s, n) for(int i = s; i < n; i++) 

int main() {
    int n, k;
    cin >> n >> k;
    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        ans += (n/i)*max(0, i-k);
        //ans += max(0, n%i-k+1);
        if(k == 0) ans += n%i;
        else ans += max(0, n%i-k+1);
    }
    cout << ans << endl;
    return 0;
}