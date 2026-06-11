#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
/* ------------------------------------------------ */
ll fact(int i) {       //階乗
    if (i == 0) return 1;
    return (fact(i - 1)) * i;
}
ll gcd(ll a, ll b) {        //最大公約数
    if(b == 0) return a;
    return gcd(b, a % b); 
}
ll lcm(ll a, ll b) {      //最小公倍数
    return a * b / gcd(a, b);
}
int keta(ll n) {        //桁数を求める
    if(n == 0) return 1;
    int count = 0;
    while(n != 0) {
        n /= 10;
        count++;
    }
    return count;
}
ll ketasum(ll n) {    //各桁の和
    ll sum = 0;
    while(n != 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}
/* ------------------------------------------------ */
int main() {
    ll a, b, c, k;
    cin >> a >> b >> c >> k;
    /*rep(i, k) {
        ll p = b + c;
        ll q = c + a;
        ll r = a + b;
        a = p; b = q; c = r;
        cout << a << ' ' << b << ' ' << c << endl;
    }
    if(abs(a - b) > 1e18) {
        cout << "Unfair" << endl;
        return 0;
    }*/
    if(abs(a - b) > 1e18) {
        cout << "Unfair" << endl;
    }
    else if(k % 2 == 0){
        cout << a - b << endl;
    }
    else cout << b - a << endl;
    return 0;
}
