#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7/*998244353*/;
const ll INF = 1LL << 60;
ll mod_pow(ll, ll, ll); ll mod_fact(ll, ll); ll mod_inv(ll, ll); ll gcd(ll, ll); ll lcm(ll, ll);
//
int main(){
    ll a, b;
    cin >> a >> b;
    int cnt = 0;
    while(a <= b){
        cnt++;
        a *= 2;
    }
    cout << cnt;
}