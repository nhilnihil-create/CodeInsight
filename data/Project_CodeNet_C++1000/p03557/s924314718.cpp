#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) (x).begin(),(x).end()
#define cyes cout<<"YES"<<endl
#define cno cout<<"NO"<<endl
#define sp <<" "<<
#define cst(x) cout<<fixed<<setprecision(x)
#define pi 3.14159265359
#define mod 1000000007
using namespace std;
using ll = long long;
using ld = long double;
using Graph = vector<vector<int>>;
using que_a = priority_queue<int, vector<int>, greater<int> >;
using que_d = priority_queue<int>;
using pint = pair<int,int>;



int main(){

    int n; cin >> n;
    vector<ll> a(n),b(n),c(n);
    rep(i,n) cin >> a.at(i);
    rep(i,n) cin >> b.at(i);
    rep(i,n) cin >> c.at(i);
    sort(all(a));
    sort(all(b));
    sort(all(c));
    ll ans = 0;

    rep(i,n){
        auto x = lower_bound(all(a),b.at(i));
        auto y = upper_bound(all(c),b.at(i));
        ans +=  (x - a.begin())*(c.end() - y);

    }
    cout << ans << endl;
    return 0;   
}
