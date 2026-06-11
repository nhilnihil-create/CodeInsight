#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mx = 10000007;
const ll mod = 1e9 + 7;
const double pi = acos(-1);
#define gcd(a, b) __gcd((a), (b))
#define lcm(a, b) ((a) / __gcd((a), (b)) * (b))
#define FIO ios_base::sync_with_stdio(false);  cin.tie(NULL);

void decision(ll a, ll b) {
    a =min(a, b);
}

int main() {
    ll n, a;
    cin >> n;
   ll c = 0;
   while(n--) {
       cin >> a;
    while(a % 2 != 1) {
        a = a/2;
        c++;
    }
   }
    cout << c << endl;
}

