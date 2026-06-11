#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N,K;
    cin >> N >> K;
    vector<ll> vec(N);
    for(int i = 0; i < N; i++){
        cin >> vec.at(i);
    }

    sort(vec.begin(),vec.end());
    ll ans = 1000000000;
    for(int i = 0; i < N - K + 1; i++){
        ll H = vec.at(i+K-1) - vec.at(i);
        ans = min(ans, H);
    }
    cout << ans << endl;
}