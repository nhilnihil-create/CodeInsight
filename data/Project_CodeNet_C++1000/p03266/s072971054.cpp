#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    ll n, k, a, b;
    cin >> n >> k;
    a = n / k;
    b = (n + k / 2) / k;
    if (k % 2) cout << a * a * a;
    else cout << a * a * a + b * b * b;
}
