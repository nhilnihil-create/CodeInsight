#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<long long> v;
    long long ans = 0;
    for(int i = 0; i < n; i++){
        long long a, b;
        cin >> a >> b;
        v.push_back(a+b);
        ans -= b;
    }
    sort(v.rbegin(), v.rend());
    for(int i = 0; i < n; i++){
        if(i%2 == 0) ans += v[i];
    }
    cout << ans << endl;
    return 0;
}