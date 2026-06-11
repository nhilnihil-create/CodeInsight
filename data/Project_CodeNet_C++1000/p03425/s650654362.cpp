#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
#define rep(i,n) for(ll i=0;i<(n);i++)
#define pll pair<ll,ll>
#define pq priority_queue
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(c,x) distance(c.begin(),lower_bound(all(c),x))
#define ub(c,x) distance(c.begin(),upper_bound(all(c),x))

using namespace std;

template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}

const ll mod=1e9+7;

int main(){
    ll n;
    cin >> n;
    vector<set<string>> a(5);
    rep(i,n){
        string s;
        cin >> s;
        if(s[0]=='M') a[0].insert(s);
        if(s[0]=='A') a[1].insert(s);
        if(s[0]=='R') a[2].insert(s);
        if(s[0]=='C') a[3].insert(s);
        if(s[0]=='H') a[4].insert(s);
    }
    ll ans=0;
    for(ll i=0;i<(1<<5);i++){
        ll cnt=0;
        ll cur=1;
        rep(j,5){
            if((i>>j)%2==1) cnt++;
        }
        if(cnt==3){
            rep(j,5){
                if((i>>j)%2==1){
                    cur*=a[j].size();
                }
            }
            ans+=cur;
        }
        
    }
    cout << ans << endl;
} 
