#include <bits/stdc++.h>
#include <algorithm>
#define rep(i, n) for (ll i=0; i<n; ++i)
#define all(obj) (obj).begin(),(obj).end()
using namespace std;
typedef long long ll;
long long GCD(long long x, long long y) { return y ? GCD(y, x%y) : x; }

int main(){
    ll N, M;
    cin >> N >> M;
    ll goukei = N*M;
    cout << abs(goukei-(N*2)-(M-2)*2) << endl;
    return 0;
}
