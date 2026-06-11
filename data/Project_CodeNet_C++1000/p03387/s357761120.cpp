#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mx = 10000007;
const ll mod = 1e9 + 7;
const double pi = acos(-1);
#define    ss   second
#define    ff   first
#define    pb   push_back
#define gcd(a, b) __gcd((a), (b))
#define lcm(a, b) ((a) / __gcd((a), (b)) * (b))
#define FIO ios_base::sync_with_stdio(false);  cin.tie(NULL);


int main() {
    FIO;
    ll a[3];
    for(ll i = 0; i < 3; i++) {
        cin >> a[i];
    }
    sort(a, a+3);
    ll A = a[0];
    ll B = a[1];
    ll C = a[2];


    ll k = C - B;
    ll j = A + k;
    ll l = C - j;
    ll p;
    if(l % 2 == 0) {
         p = ceil(l / 2.0);
    }
    else {
         p = ceil(l / 2.0) + 1;
    }
    ll g = p + k;
    cout << g << endl;
    return 0;
}
