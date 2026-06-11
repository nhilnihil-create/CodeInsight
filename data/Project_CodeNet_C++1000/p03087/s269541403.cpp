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
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    ll cnt[n] = {0};
    for (ll i = 1; i < s.size(); i++) {
        if(s[i-1] == 'A' && s[i] == 'C') {
            cnt[i] = cnt[i-1] + 1;
        }
        else {
            cnt[i] = cnt[i-1];
        }
    }
    while(k--) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;

        cout << cnt[b] - cnt[a] << endl;
    }


}
