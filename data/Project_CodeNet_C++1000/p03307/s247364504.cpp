#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll INF = 1e18;
ll MOD = 1e9+7;
//最大公約数
ll gcd(ll a, ll b) {
    return b ? gcd(b, a%b) : a;
}




//最小公倍数、最大公約数を使って求める
ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}


int main(){
    ll N; cin >> N;
    cout << lcm(2, N) << endl;;
}