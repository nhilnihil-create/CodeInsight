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

const ll INF=1e18;

int main()
{
    string s;
    cin >> s;
    ll n=s.length();
    bool ok=true;
    if(s[0]!='A') ok=false;
    ll cnt1=0;
    for(ll i=2;i<=n-2;i++){
        if(s[i]=='C') cnt1++;
    }
    ll cnt2=0;
    rep(i,n){
        if((ll)(s[i]-'A')<=30) cnt2++;
    }
    if(ok && cnt1==1 && cnt2==2) cout << "AC" << endl;
    else cout << "WA" << endl;
    return 0;
} 