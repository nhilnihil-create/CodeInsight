#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define V vector
#define P pair
typedef long long ll;
const int INT_INF = 1e9;
const ll INF = 1LL << 30;

int main() {
    ll n; cin >> n;
    V<ll> c(n), s(n), f(n);
    for(int i = 0; i < n; i++) cin >> c[i] >> s[i] >> f[i];

    for(int i = 0; i < n - 1; i++){
        ll sum = 0;
        for(int j = i; j < n - 1; j++){
            if(sum < s[j]){
                sum = s[j];
            }else if(sum % f[j] == 0){
            }else{
                sum += f[j] - (sum % f[j]);
            }
            sum += c[j];
        }
        cout << sum << endl;
    }
    cout << 0 << endl;
}
