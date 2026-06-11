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
    int n,k;
    cin >> n >> k;
    vector<int> h(n);
    rep(i,n) cin >> h[i];
    sort(h.begin(),h.end());
    int mi = 2000000000;
    rep(i,n-k+1){
        mi = min (mi,h[i+k-1]-h[i]);
    }
    cout << mi <<endl;
}
