#include <bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define rep(i, n) for(int i = 0; i < n; i++)
#define repp(i, n) for(int i = 1; i <= n; i++)
#define sort(v) sort((v).begin(), (v).end())
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(),(a).end()
#define riverse(v) reverse((v).begin(), (v).end())
using vi = vector<int>;
using vs = vector<string>;
using vvi = vector<vi>;
using vll = vector<ll>;
const ll MOD = 1e9+7;
vi alphabet = {'a','b','c','d','e','f','g','h','i','j','k','l','m',
               'n','o','p','q','r','s','t','u','v','w','x','y','z'};

int main() {
    ll n, k;
    cin >> n >> k;
    ll count = 0;
    for (ll b = k + 1; b <= n; b++) {
        ll c = n / b;
        count += (b - k) * c;
        if (n % b >= k) count += n % b - k + 1;
    }
    if (k != 0) {
        cout << count << endl;
    }
    else cout << count - n << endl;
}