#include <bits/stdc++.h>
using namespace std;
#define PI 3.141592653589793
#define MOD 1000000007
typedef long long ll;
typedef long double ld;

int main() {
    ll N, K;
    cin >> N >> K;
    vector<ll> x(N, 0);
    for(int i = 0; i < N; i++){
        cin >> x[i];
    } 
    
    ll ans = MOD;
    
    for(int i = 0; i < N - K + 1; i++){
        ll tmp_ans = abs(x[i]);
        tmp_ans += abs(x[i + K - 1] - x[i]);
        ll tmp_ans2 = abs(x[i + K - 1]);
        tmp_ans2 += abs(x[i + K - 1] - x[i]);
        tmp_ans = min(tmp_ans2, tmp_ans);
        ans = min(ans, tmp_ans);
    }
    cout << ans << endl;
}
