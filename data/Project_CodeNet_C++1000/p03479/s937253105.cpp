#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll min, max;
    cin >> min >> max;

    vector<ll> A;
    A.push_back(min);
    ll n = min;

    for(;;) {
        n *= 2;
        if(n > max) {
            break;
        }
        A.push_back(n);
    }
    cout << A.size() << endl;
}