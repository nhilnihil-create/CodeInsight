#include <cmath>
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll inf = 1000000007;
ll h[100005];
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    int active = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (active < h[i]) {
            ans += h[i]-active;
            active = h[i];
        }
        else {
            active = h[i];
        }
    }
    cout << ans << endl;
    return 0;
}