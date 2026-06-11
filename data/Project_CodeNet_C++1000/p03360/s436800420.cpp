#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>

typedef long long ll;
using namespace std;
const ll INF = 1e9;
const ll MOD = 1e9 + 7;
#define repi(i, n, init) for(ll i=init;i<(n);i++)

int main() {
    int a, b, c, k;
    cin >> a >> b >> c >> k;
    
    cout << max({a, b, c}) * pow(2, k) + a + b + c - max({a,b,c})<< endl;
    return 0;
}