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

 vector<pair<ll, ll>>v(mx+1);
ll t[mx+1] = {};
int N, X[mx], Y[mx], T[mx];

int main() {
    FIO;
    ll n;
    cin >> n;
       for (ll i = 1; i <= n; i++) {
            cin >> T[i] >> X[i] >> Y[i];

    }

    for (ll i = 1; i <= n; i++) {
        int tm = T[i] - T[i - 1];
		int ds = abs(X[i] - X[i - 1]) + abs(Y[i] - Y[i - 1]);
		if (ds > tm || (tm - ds) % 2 == 1) {
			cout << "No" << endl;
			return 0;
		}
    }
cout << "Yes" << endl;
}
