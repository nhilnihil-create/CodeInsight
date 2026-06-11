#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
ll n, k, q, a[2020], ans;
vector<ll> V, W;
const ll INF = 10000000000;
int main(void){
    // Your code here!
    ans = INF;
    cin >> n >> k >> q;
    for (ll i = 0; i < n; i++) cin >> a[i];
    for (ll i = 0; i < n; i++){
        for (ll j = 0; j <= n; j++){
            if (j != n && a[j] >= a[i]){
                V.push_back(a[j]);
            } else {
                if (V.size() >= k){
                    sort(V.begin(), V.end());
                    for (ll l = 0; l < V.size() - k + 1; l++){
                        W.push_back(V[l]);
                    }
                }
                V.erase(V.begin(), V.end());
            }
        }
        if (W.size() >= q){
            sort(W.begin(), W.end());
            ans = min(ans, W[q - 1] - W[0]);
        }
        W.erase(W.begin(), W.end());
    }
    cout << ans << endl;
}
