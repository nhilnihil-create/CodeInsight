#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define V vector
#define P pair
typedef long long ll;
const int INT_INF = 1e9;
const ll INF = 1LL << 30;

int main() {
    int n; cin >> n;
    V<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    int ans = v[0];
    for(int i = 1; i < n; i++){
        if(v[i] > v[i - 1]){
            ans += v[i] - v[i - 1];
        }
    }
    cout << ans << endl;
}
