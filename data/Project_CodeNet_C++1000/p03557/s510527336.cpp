#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using ll = long long;
using P = pair<int,int>;
ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}
const ll INF = 1LL<<60;




int main()
{
    int N;
    cin >> N;
    vector<int> a(N);
    vector<int> b(N);
    vector<int> c(N);
    rep(i,N) cin >> a[i];
    rep(i,N) cin >> b[i];
    rep(i,N) cin >> c[i];

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    sort(c.begin(),c.end());

    ll ans = 0;
    rep(i,N){
        ll anum,cnum;
        auto Iter_a = lower_bound(a.begin(),a.end(),b[i]);
        auto Iter_c = upper_bound(c.begin(),c.end(),b[i]);
        if(b[i] <= a[Iter_a - a.begin()]) anum = Iter_a - a.begin();
        else anum = a.size();
        if(b[i] < c[Iter_c - c.begin()]) cnum = c.end() - Iter_c;
        else cnum = 0;
        ans += anum * cnum;
    }

    cout << ans << endl;

    return 0;
}
//Ctrl+Shift+Bでコンパイルと実行を行ってデバッグすること