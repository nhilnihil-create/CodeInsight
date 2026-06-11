#include <bits/stdc++.h>
#include <algorithm>
#define rep(i, n) for (ll i=0; i<n; ++i)
#define all(obj) (obj).begin(),(obj).end()
using namespace std;
typedef long long ll;
long long GCD(long long x, long long y) { return y ? GCD(y, x%y) : x; }

int main(){
    ll N;
    cin >> N;
    ll a;
    cin >> a;
    for(int i=1; i<N; ++i){
        ll b;
        cin >> b;
        a = GCD(a, b);
    }
    cout << a << endl;
    return 0;
}
