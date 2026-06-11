#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> P;

ll gcd (ll a, ll b) {
    if (b > a) {
        ll tmp = b;
        b = a;
        a = tmp;
    }
    if (b == 0) return a;
    return gcd(b, a % b);
}

ll lcm (ll a, ll b) {
    return a * b / gcd (a, b);
}


int main(){
    int N;
    cin >> N;
    vector<int> a(N);
    ll tmp = 1;
    for(int i = 0; i < N; i++) {
        cin >> a.at(i);
        //tmp = lcm(tmp, a.at(i));
    }

    //tmp--;
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        //ans += tmp % a.at(i);
        ans += a.at(i) - 1;
    }
    
    cout << ans << endl;
    return 0;
}
