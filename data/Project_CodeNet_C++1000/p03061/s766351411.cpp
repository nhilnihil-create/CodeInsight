#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = 1; i <= n; i++)
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { return (a * b) / gcd(a,b); }
using P = pair <int, int>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

ll MOD = 1000000007;
ll INF =1<<29;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<int> x(n+1),y(n+1);
    x[0]=0;y[0]=0;
    rep(i,n){
        x[i+1] = gcd(x[i],a[i]);
    }
    vector<int> b = a;
    reverse(b.begin(),b.end());
    rep(i,n){
        y[i+1] = gcd(y[i],b[i]);
    }
    ll ma = 0;
    rep(i,n){
        ma = max(ma,gcd(x[i],y[n-i-1]));
    }
    cout << ma << endl;
}
