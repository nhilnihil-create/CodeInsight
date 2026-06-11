#include <bits/stdc++.h>
#include <algorithm>
#define rep(i, n) for (int i=0; i<n; ++i)
#define all(obj) (obj).begin(),(obj).end()
using namespace std;
typedef long long ll;
long long GCD(long long x, long long y) { return y ? GCD(y, x%y) : x; }

int main(){
    ll N, K;
    ll mi = 1001001001;
    cin >> N >> K;
    vector<ll> h(N);
    rep(i, N) cin >> h[i];
    sort(all(h));
    rep(i, N-K+1){
        mi = min(h[i+K-1]-h[i], mi);
    }
    cout << mi << endl;
    return 0;
}
