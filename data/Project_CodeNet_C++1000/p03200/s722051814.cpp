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
    string s;
    cin >> s;
    ll n = s.size();
    ll bla = 0,whi=0;
    rep(i,n){
        if(s[i]=='B')bla++;
        else whi++;
    }
    ll ans1=0,ans2=0;
    rep(i,n){
        if(s[i]=='B') ans1+=i;
    }
    for(int i = whi;i<n;i++)ans2+=i;
    cout << ans2-ans1<<endl;
}