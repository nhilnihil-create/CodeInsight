#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T>
using vec = std::vector<T>;

int main() {
    int N;
    cin >> N;
    vec<ll> A(N);
    rep(i, N) cin >> A[i];

    ll ans   = 0;
    ll msk   = A[0];
    ll left  = 0;
    ll right = 0;
    while (right <= N - 1) {
        if (left == right){
            ++ans;
            ++right;
            msk = A[left];
        } else if ((msk ^ A[right]) == msk + A[right]) {
            ++ans;
            msk ^= A[right];
            ++right;
        } else {
            msk ^= A[left];
            ++left;
            ans+=(right-left);
        }
        
    }
    ll count = right - left - 1;
    ans += count * (count - 1) / 2;
    ans += count;

    cout << ans << endl;
}