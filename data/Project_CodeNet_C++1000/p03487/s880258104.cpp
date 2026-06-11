#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = 1; i <= n; i++)
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { return (a * b) / gcd(a,b); }
using P = pair <int, int>;
 
ll MOD = 1000000007;
ll INF =1<<29;
 
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    map<int,int> mp;
    rep(i,n){
        mp[a[i]]++;
    }
    int ans = 0;
    for(auto p:mp){
        if(p.first>p.second){
            ans+=p.second;
        }
        else if(p.first<p.second){
            ans += p.second-p.first;
        }
    }
    cout << ans <<endl;
}
