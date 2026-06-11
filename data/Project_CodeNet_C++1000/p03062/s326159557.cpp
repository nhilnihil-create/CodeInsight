#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
typedef long long ll;
const int INT_INF = 1e9;
const ll INF = 1LL << 30;
const ll MOD = 1e9 + 7;


int main() {
    int n; cin >> n;
    V<ll> a(n);
    ll sum = 0, cnt = 0, zero = 0, mi = INF;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] < 0) cnt++;
        if(a[i] == 0) zero++;
        sum += abs(a[i]);
        mi = min(mi, abs(a[i]));
    }

    if(cnt % 2 == 0 || zero){
        cout << sum << endl;
    }else{
        cout << sum - mi * 2 << endl;
    }

}
