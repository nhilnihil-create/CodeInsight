#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    ll N, K; cin >> N >> K;
    if(K % 2 == 1){
        ll x = N/K;
        x = pow(x, 3);
        cout << x << endl;
    } else {
        ll x = N/K;
        x = pow(x, 3);
        if(N - K/2 < 0){
            cout << x << endl;
            return 0;
        }
        ll y = (N - K/2) / K;
        y++;
        y = pow(y, 3);
        cout << x + y << endl;
    }

    return 0;
}