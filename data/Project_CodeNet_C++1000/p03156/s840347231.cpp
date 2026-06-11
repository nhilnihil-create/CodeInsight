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
ll INF =1<<30;

int main(){
    int n,a,b;
    cin >> n >> a>>b;
    vector<int>p(n);
    rep(i,n) cin >> p[i];
    int x=0,y=0,z=0;
    rep(i,n){
        if(p[i]<=a) x++;
        else if(p[i]>=b+1) z++;
        else y++;
    }
    cout << min(x,min(y,z)) <<endl;
}