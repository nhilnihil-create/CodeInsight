#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll gcd(ll x, ll y) { return (x % y)? gcd(y, x % y): y; }


int main(){
    ll N , X;
    cin >> N >> X;
    vector<ll> x(N + 1 , 0);
    vector<ll> num(N , 0);

    x[0] = X;
    for(int i = 1; i <= N; i++) cin >> x[i];

    for(int i = 0; i < N; i++)   num[i] = abs(x[i] - x[i + 1]);

    ll ans = 0;
    ll a = num[0];
    for (int i = 1; i < N; i++) {
        a = gcd(a, num[i]);
    }
    cout << a << endl;

}
