#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;
#define ll long long
#define all(x) x.begin(), x.end()
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
const int N = 1e5 + 10;
const double eps = 1e-9;

int main() {
    ll d, n;
    cin >> d >> n;
    ll ans = 1;
    while (d--)
        ans *= 100;

    cout << (n < 100 ? ans * n : ans * (n + 1)) << endl;
}