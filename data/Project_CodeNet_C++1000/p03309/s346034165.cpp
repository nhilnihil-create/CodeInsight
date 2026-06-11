#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
typedef long long ll;

int main() {
    ll N,A,r=0;
    cin >> N;
    vector<ll> t(N);
    rep(i,N) {
        cin >> A;
        t.at(i) = A-(i+1);
    }
    sort(t.begin(), t.end());

    if(N%2)
        rep(i,N)
            r += abs(t.at(i)-t.at(N/2));
    else {
        ll r1,r2;
        rep(i,N) {
            r1 += abs(t.at(i)-t.at(N/2-1));
            r2 += abs(t.at(i)-t.at(N/2));
        }
        r = min(r1,r2);
    }

    cout << r << endl;
}