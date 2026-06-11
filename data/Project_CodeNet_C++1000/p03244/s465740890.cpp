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
    vector<ll>a(100009, 0), b(100009, 0);
    for (ll i = 0; i < n; i++) {
        ll x;
        cin >> x;
        if(i % 2 == 1) {
            b[x]++;
        }
        else {
            a[x]++;
        }
    }
    ll ans = 0;
    ll amax = max_element(a.begin(), a.end()) - a.begin();
    ll bmax = max_element(b.begin(), b.end()) - b.begin();

    if(amax != bmax) {
        ans = n - a[amax] - b[bmax];
    }

    else {
        sort(a.begin(), a.end(), greater<ll>());
        sort(b.begin(), b.end(), greater<ll>());

        ans = min(n - (a[0] + b[1]), n - (a[1] + b[0]));
    }

    cout << ans << endl;
    return 0;

}

