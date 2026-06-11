#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mx = 10000007;
const ll mod = 1e9 + 7;
const double pi = acos(-1);
#define gcd(a, b) __gcd((a), (b))
#define lcm(a, b) ((a) / __gcd((a), (b)) * (b))
#define FIO ios_base::sync_with_stdio(false);  cin.tie(NULL);
ll n;
ll c = 0;
void nmbr(ll x, bool f1, bool f2, bool f3) {
    if(x > n)
        return;
    if(f1 && f2 && f3)
        c++;
        nmbr(x*10+3, true, f2, f3);
        nmbr(x*10+5, f1, true, f3);
        nmbr(x*10+7, f1, f2, true);

}

int main() {
    cin >> n;
    nmbr(0, 0, 0, 0);
    cout << c << endl;
}

