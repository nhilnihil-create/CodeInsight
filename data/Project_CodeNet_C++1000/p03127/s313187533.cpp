#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    rep(i,N) cin >> A.at(i);
    while (true) {
        sort(A.begin(), A.end());
        int position = distance(A.begin(), upper_bound(A.begin(), A.end(), 0));
        ll mod = A.at(position);
        for (auto i = position + 1; i < N; ++i) {
            A.at(i) %= mod;
        }
        if (position == N - 1) {
            cout << A.at(position) << endl;
            return 0;
        }
    }
}
