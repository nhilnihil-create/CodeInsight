#include <bits/stdc++.h>
#define ll long long
#define SIZE_OF_ARRAY(array) (sizeof(array)/sizeof(array[0]))
#define INF = 1001001001
#define pi = acos(-1)
using namespace std;

ll gcd(ll x, ll y) { return (x % y)? gcd(y, x % y): y; }
ll lcm(ll x, ll y) { return (x * y) / gcd(x, y); }


int main(){
    ll n, k; cin >> n >> k;
    vector<ll> h(n);
    ll min = 1000000001;
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }

    sort(h.begin(), h.end());
    for (int j = 0; j < n-k+1; ++j) {
        if(h[j+k-1]-h[j] < min) min = h[j+k-1] - h[j];
    }

    cout << min << endl;
}
