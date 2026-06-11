#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ll n, m;
    cin >> n >> m;
    ll count = 1LL<<m;
    ll each_time = 1900LL * m + 100LL * (n - m);
    cout <<  each_time * count << endl;
}