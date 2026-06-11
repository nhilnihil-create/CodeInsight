#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    ll N; cin >> N;
    for (ll i = 1; i < 3501; i++){
        for (ll j = 1; j < 3501; j++){
            ll ue = N * i * j;
            ll shita = 4 * i * j - N * i - N * j;
            if(shita < 1)continue;
            if(ue % shita == 0){
                ll k = ue / shita;
                cout << i << " " << j << " " << k << endl;
                return 0;
            }
        }
    }

    return 0;
}