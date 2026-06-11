#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(ll i = 0; i < (ll)(n); i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF = 1LL << 60;
int main(){
    ll n,m;
    string s,t;
    cin >> n >> m >> s >> t;
    ll gcd = __gcd(n,m);
    ll l = n*m/gcd;
    ll n2 = n / gcd;
    ll m2 = m / gcd;
    int cur = 0;
    while(n2*cur<s.size()){
        if(s[n2*cur]!=t[m2*cur]){
            cout << -1 << endl;
            return 0;
        }
        cur++;
    }
    cout << l << endl;
    return 0;
}