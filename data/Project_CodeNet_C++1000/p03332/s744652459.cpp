/*
Я засыпаю в темноте, и страшно мне открыть глаза
Я засыпаю в темноте - и помню все, что сделал сам
Я засыпаю в темноте, не добрых мыслей жуткий рой
Я засыпаю в темноте, а завтра - я проснусь другой
*/
#pragma ARCENIY_KIRILLOV_POVELITEL_KROKODILOV
//#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("no-stack-protector")
//#pragma GCC push_options
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC pop_options
#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define rng(a) a.begin(), a.end()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define rep(i, n) for (int i = 0; i < n; i++)
#define per(i, n) for (int i = n - 1; i > -1; i--)
#define rer(i, x, n) for (int i = x; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vp;
typedef long double ld;

const double EPS = 1e-5;
const int mod = 1e9 + 7;
const int fft_mod = 998244353;
const ll INFLL = 1e18;
const int INF = 1e9;
const int maxn = 1e5 + 3;

ll gcd(ll a, ll b){
    if (b == 0ll)
        return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b){
    return (a / gcd(a, b) )* b;
}

bool is_prime(ll a){
    if (a == 2 || a == 3 || a == 5 || a == 7) return true;
    if (a % 2 == 0 || a%3 == 0 || a%5 == 0 || a%7 == 0)
        return false;
    for (ll i = 11; i * i <= a; i += 2){
        if (a % i == 0)
            return false;
    }
    return true;
}

ll binpow(ll a, int n){
    if (n == 0)
        return 1;
    if (n % 2 == 0){
        ll q = binpow(a, n / 2);
        return (q * q) % fft_mod;
    }else return (a * binpow(a, n - 1) ) % fft_mod;
}

istream& operator>>(istream &in, pair<int, int> &p) {
    in >> p.fi >> p.se;
    return in;
}

ostream& operator<<(ostream &out, pair<int, int> &p) {
    out << p.fi << " " << p.se << endl;
    return out;
}



















main(){
    ll n, a, b, k;
    cin >> n >> a >> b >> k;
    if (k == 0){
        cout << 1;
        return 0;
    }
    ll fact[n + 1];
    fact[0] = 1;
    ll obr_fact[n + 1];
    obr_fact[0] = 1;
    for (ll i = 1; i <= n; i++){
        fact[i] = (fact[i - 1] * i) % fft_mod;
        obr_fact[i] = binpow(fact[i], fft_mod - 2);
    }
    ll ans = 0;
    for (ll j = 0; j <= n; j++){
        ll flex = j * a;
        ll req = k - flex;
        if (req < 0) break;
        if (req % b != 0 || req/b > n) continue;
        ll fle = req/b;
        ans = (ans + (((fact[n] * ( (obr_fact[j] * obr_fact[n - j]) % fft_mod) ) % fft_mod )*( (fact[n] * ( (obr_fact[fle] * obr_fact[n - fle]) % fft_mod)) % fft_mod))%fft_mod )% fft_mod;
    }
    cout << ans;

}
