#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mx = 10000007;
const ll mod = 1e9 + 7;
const double pi = acos(-1);
#define gcd(a, b) __gcd((a), (b))
#define lcm(a, b) ((a) / __gcd((a), (b)) * (b))
#define FIO ios_base::sync_with_stdio(false);  cin.tie(NULL);


int main() {
    FIO;
    ll a, b;
    cin >> a >> b;
    ll s = a;
    ll c = 0;
    for (ll i = 1; ; i++) {
        if(s > b) {
            cout << c << endl;
            return 0;
        }
        else {
            c++;
            s = s * 2;
        }
    }
}
