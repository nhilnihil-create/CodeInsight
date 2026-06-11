#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    ll R, G, B, N;
    cin >> R >> G >> B >> N;

    ll cnt=0;
    for(ll r=0; r<=N; ++r) {
        for (ll g=0; g<=N; ++g) {
            if (((N-r*R-g*G)%B)==0 && (N-r*R-g*G)/B>=0) {
                cnt++;
            }
        }
    }

    cout << cnt << endl;
    return 0;
}