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
    ll n, k;
    cin >> n >> k;
    if(k % 2 == 1) {
        ll g = n / k;
        cout << g * g * g << endl;
    }

    else {
        ll g = n / k;
        ll h = (2 * n)/k;
        h = h - g;
        cout << h * h * h + g * g * g << endl;
    }

    return 0;
}
