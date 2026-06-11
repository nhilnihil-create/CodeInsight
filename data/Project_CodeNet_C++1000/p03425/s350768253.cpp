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
    ll n;
    cin >> n;
    ll a[5] = {};
    for (ll i = 0; i < n; i++) {
        string s;
        cin >> s;
        if(s[0] == 'M') {
            a[0]++;
        }
         if(s[0] == 'A') {
            a[1]++;
        }
         if(s[0] == 'R') {
            a[2]++;
        }
         if(s[0] == 'C') {
            a[3]++;
        }
         if(s[0] == 'H') {
            a[4]++;
        }
    }
    ll ans = 0;
    for (ll i = 0; i < 5; i++) {
        for (ll j = i + 1; j < 5; j++) {
            for (ll k = j + 1; k < 5; k++) {
                ans += (a[i] * a[j] * a[k]);
            }
        }
    }

    cout << ans << endl;
    return 0;
}
