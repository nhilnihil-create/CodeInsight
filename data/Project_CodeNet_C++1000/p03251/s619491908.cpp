//Mahmudul Alam
#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

int main() {
    ll n, m, x, y;
    cin >> n >> m >> x >> y;
    vector<ll> xn(n), yn(m);
    for(auto &i: xn) cin >> i;
    for(auto &i: yn) cin >> i;
    xn.push_back(x);
    yn.push_back(y);
    sort(xn.rbegin(), xn.rend());
    sort(yn.begin(), yn.end());
    if(xn[0] < yn[0]) cout << "No War" << endl;
    else cout << "War" << endl;
    return 0;
}