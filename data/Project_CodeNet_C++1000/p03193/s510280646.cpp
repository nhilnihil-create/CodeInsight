#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
#define PI 3.1415926535897932384626433
#define mod 1000000007
 
int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }
 
int lcm(int a, int b) { return a * b / gcd(a, b); }
 
int main(){
    ll n, h, w;
    cin >> n >> h >> w;
    ll a[n], b[n];
    for (ll i = 0; i < n; i++){
        cin >> a[i] >> b[i];
    }

    ll ans = 0;
    for (ll i = 0; i < n; i++){
        if(h <= a[i] & w <= b[i]){
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}