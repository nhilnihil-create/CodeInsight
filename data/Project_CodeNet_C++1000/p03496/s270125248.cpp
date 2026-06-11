#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T>
using vec = std::vector<T>;

int main() {
    int N;
    cin >> N;
    vec<int> a(N);
    int mx = 0;
    int mn = 0;
    rep(i, N) {
        cin >> a[i];
        mx = max(mx, a[i]);
        mn = min(mn, a[i]);
    }

    cout << N*2-1 << endl;
    if(mx >= abs(mn)){
        int idx = find(all(a),mx) - a.begin() + 1;
        rep(i,N) cout << idx << " " << i+1 << endl;
        rep(i,N-1) cout << i+1 << " " << i+2 << endl;
    } else {
        int idx = find(all(a),mn) - a.begin() + 1;
        rep(i,N) cout << idx << " " << i+1 << endl;
        for(int i=N;i>=2;--i) cout << i << " " << i-1 << endl;
    }
}