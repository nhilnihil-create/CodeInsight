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
    int n, k, one;
    cin >> n >> k;
    vi v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    cout << (n - 1 + k - 2) / (k - 1) << endl;
}