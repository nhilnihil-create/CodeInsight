#include <iostream>

using namespace std;

const long MOD = 1000000007;
typedef pair<int, int> P;
typedef long long ll;

int main(){
    int N, K;
    cin >> N >> K;

    ll x[N];
    for(int i=0; i<N; i++){
        cin >> x[i];
    }

    ll ans = 1000000000;
    for(int i=0; i<N; i++){
        if(i + K - 1 >= N) continue;
        int l = i;
        int r = i + K - 1;
        ll d1 = abs(x[r]) + abs(x[r] - x[l]);
        ll d2 = abs(x[l]) + abs(x[l] - x[r]);
        ll ta = min(d1, d2);
        ans = min(ans, ta);
    }

    cout << ans << endl;


    return 0;
}
