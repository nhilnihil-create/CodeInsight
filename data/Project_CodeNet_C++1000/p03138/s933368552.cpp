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
    int n; ll k;
    cin >> n >> k;
    vector<ll> a;
    rep(i, n){ ll tmp; cin >> tmp; a.push_back(tmp);}

    const int maxbit = 42;
    vector<int> bit(maxbit);
    vector<int> biton(maxbit, 0);
    rep(i, n){
        ll tmp = a[i];
        int itr = 0;
        while(tmp != 0 && itr < maxbit){
            bit[itr] += tmp&1ll;
            tmp >>= 1;
            itr++;
        }
    }

    
    rep(i, maxbit){
        if (bit[i] <= ((n+1)/2) - 1){
            biton[i] = 1;
        } 
    }

    ll ans = 0;
    for (int i = maxbit-1; i >= 0; i--)
    {
        if (biton[i] == 1 && ans+(1ll<<i) <= k) ans += 1ll<<i;
    }
    
    //cout << ans << endl;

    ll sum = 0;
    rep(i, n) sum += ans^a[i];
    cout << sum << endl;

}

