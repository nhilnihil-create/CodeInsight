#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;


int main(){

    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int train, bus;
    train = min(a, b);
    bus = min(c, d);
    cout << train + bus << endl;
    return 0;
}