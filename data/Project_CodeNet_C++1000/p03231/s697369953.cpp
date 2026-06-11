#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define rrep(i,a,b) for(ll i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()

//最大公約数,最小公倍数
ll gcd(ll a, ll b) { return b ? gcd(b,a%b) : a; }
ll lcm(ll a, ll b) { return a/gcd(a,b)*b; }

int main(void){
    ll n, m;
    cin >> n >> m;

    string s, t;
    cin >> s >> t;

    ll l = lcm(n, m);
    ll a = l / n;
    ll b = l / m;

    ll l2 = lcm(a, b);


    for(int i = 0; i < l / l2; i++){
        if(s[i * l2 / a] != t[i * l2 / b]){
            cout << "-1" << endl;
            return 0;
        }
    }

    cout << l << endl;
    return 0;

}
