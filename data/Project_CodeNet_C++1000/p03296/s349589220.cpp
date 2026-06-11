#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<int>a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    ll ans = 0;
    for (int i = 1; i < N; ++i) {
        if(a[i] == a[i-1]) {
            ans++;
            i++;
        }
    }
    cout << ans;
    return 0;
}