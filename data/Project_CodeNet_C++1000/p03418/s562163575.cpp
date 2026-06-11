#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for (int i = 0; i < (n); ++i)
typedef long long ll;

int main() {
    ll N,K,r=0;
    cin >> N >> K;

    if(K == 0) {
        cout << N*N << endl;
        return 0;
    }

    rep(i,N-K) {
        r += (N/(i+K+1))*(i+1);
        r += max(N%(i+K+1)-K+1, (ll)0);
    }
    cout << r << endl;
}