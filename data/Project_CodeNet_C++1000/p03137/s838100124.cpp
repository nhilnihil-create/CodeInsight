#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n, m;
    cin >> n >> m;

    swap(n, m);

    vector<ll> arr(n), delta;

    for (int i = 0; i < n; i++) cin >> arr[i];

    sort(arr.begin(), arr.end());

    for (int i = 1; i < n; i++) {
        delta.push_back(arr[i] - arr[i-1]);
    }

    if (n <= m) {
        cout << 0 << endl;
        return 0;
    }

    sort(delta.begin(), delta.end());
    
    ll max_x = arr.back() - arr.front(), max_delta = 0;
    for (int i = 0; i < m-1; i++) {
        max_delta += delta.back();
        delta.pop_back();
    }

    cout << max_x - max_delta << endl;
    return 0;
}
