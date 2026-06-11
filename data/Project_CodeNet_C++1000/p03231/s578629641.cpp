#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPR(i, n) for (int i = n - 1; i >= 0; --i)
#define FOR(i, m, n) for (int i = m; i < n; ++i)
#define FORR(i, m, n) for (int i = m; i >= n; --i)
#define ALL(v) (v).begin(),(v).end()
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF=1LL<<60;
const int inf=(1<<30)-1;
const int mod=1e9+7;
int dx[8]={1,0,-1,0,-1,-1,1,1};
int dy[8]={0,1,0,-1,-1,1,-1,1};
ll gcd(ll a,ll b){
    return (b?gcd(b,a%b):a);
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,m;cin >> n >> m;
    string s,t;cin >> s >> t;
    ll g=gcd(n,m);
    ll u=n/g,v=m/g;
    FOR(i,0,g){
        if(s[i*u]!=t[i*v]){
            cout << -1 << endl;
            return 0;
        }
    }
    cout << n*m/g << endl;
}