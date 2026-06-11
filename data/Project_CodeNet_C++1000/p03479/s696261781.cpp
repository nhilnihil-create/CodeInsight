#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll x, y; cin >> x >> y;
    int count = 1;
    ll val = x;
    while (true) {
        val *= 2;
        if (val > y) break;
        count ++;
    }
    cout << count << endl; 
}