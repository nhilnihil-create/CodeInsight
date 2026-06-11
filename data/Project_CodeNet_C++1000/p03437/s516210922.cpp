#include <iostream>
#include <cmath>
using namespace std;
using ll = long long;
ll solve() {
    ll X, Y;
    cin >> X >> Y;
    ll t = (ll)1e18 / X - (ll)1e18 / X / Y;
    if (t <= 0 || X % Y == 0) return -1;
    return X * (Y + 1);
}
int main() {
    cout << solve() << endl;
}
