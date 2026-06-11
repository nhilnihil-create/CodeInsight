#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i++)
#define show(x) {for(auto i: x){cout << i << " ";} cout<<endl;}
#define showm(m) {for(auto i: m){cout << m.x << " ";} cout<<endl;}
typedef long long ll;
typedef pair<int, int> P;
ll gcd(int x, int y){ return y?gcd(y, x%y):x;}
ll lcm(ll x, ll y){ return (x*y)/gcd(x,y);}


int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> x;
    rep(i, n){ int tmp; cin >> tmp; x.push_back(tmp);}

    ll ans = MOD;
    rep(i, n-k+1){
        ll tans = 0;
        ll l = x[i];
        ll r = x[i+k-1];

        ll hugo = (ll)l * (ll)r;
        if (hugo < 0){
            tans = min(abs(l)*2+abs(r), abs(r)*2+abs(l));
        } else {
            tans = max(abs(l),abs(r));
        }
        ans = min(ans, tans);
    }
    cout << ans << endl;
}

