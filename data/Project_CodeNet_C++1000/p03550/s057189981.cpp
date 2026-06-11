#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main(){
    int n;
    cin >> n;
    ll z, w;
    cin >> z >> w;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    if ( n == 1 ) {
        cout << abs(a[0] - w) << endl;
        return 0;
    }
    cout << max(abs(a[n-1]-w), abs(a[n-1]-a[n-2])) << endl;
//    cout << abs(a[n-1]-w) << " "<< abs(a[n-1]-a[n-2]) << endl;
    return 0;
}
