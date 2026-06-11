#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i++)
#define showmap(is, js, x) {rep(i, is){rep(j, js){cout << x[i][j] << " ";}cout << endl;}}
#define show(x) {for(auto i: x){cout << i << " ";} cout<<endl;}
#define showm(m) {for(auto i: m){cout << m.x << " ";} cout<<endl;}
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> llP;
ll gcd(int x, int y){ return y?gcd(y, x%y):x;}
ll lcm(ll x, ll y){ return (x*y)/gcd(x,y);}


int main()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    ll asum = 0;
    ll bsum = 0;
    rep(i, n) {cin >> a[i]; asum+=a[i];}
    rep(i, n) {cin >> b[i]; bsum+=b[i];}

    ll act = bsum-asum;
    if (act < 0) {cout << "No" << endl; return 0;}

    ll need_act = 0;
    rep(i, n){
        if (a[i] > b[i]){
            need_act += a[i]-b[i];
        } else if ((b[i]-a[i])%2 == 1){
            need_act += 1;
        }
    }
    if (need_act > act) cout << "No" << endl;
    else cout << "Yes" << endl;
}
