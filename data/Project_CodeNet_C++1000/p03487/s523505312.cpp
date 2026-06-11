#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;
const ll C = 1e9+7;

int main() {
    int N;
    cin >> N;
    map<int, int> M;
    for(int i=0; i<N; i++) {
        int x;
        cin >> x;
        M[x]++;
    }

    ll ans = 0;
    ll count = 0;
    for(auto m:M) {
        count += m.first;
        if(m.second > m.first) ans += m.second - m.first;
        if(m.second < m.first) ans += m.second;
    }
    cout << ans << endl;
}