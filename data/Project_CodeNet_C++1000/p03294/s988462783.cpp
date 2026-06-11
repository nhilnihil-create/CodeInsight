//Author: Mohit Hotwani
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define SPEED ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int main() {
    SPEED;
    int testCases = 1;
    //cin >> testCases;
    while (testCases--) {
        ll n;
        cin >> n;
        ll sum = 0;
        for (ll i = 0; i < n; i++) {
            ll temp;
            cin >> temp;
            sum += temp;
        }
        cout << sum-n << endl;
    }
    return 0;   
}