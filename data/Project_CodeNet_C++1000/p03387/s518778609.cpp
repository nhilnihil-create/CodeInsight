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

int main(){
    vector<ll> a(3);
    rep(i,3){
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    vector<bool> b(3);
    rep(i,3){
        if((a[i]-a[(i+1)%3])%2==0){
            b[i]=true;
        }
    }
    if(b[0] && b[1] && b[2]){
        cout << (2*a[2]-a[0]-a[1])/2 << endl;
        return 0;
    }
    if(b[0]){
        cout << (2*a[2]-a[0]-a[1]-2)/2+1 << endl;
        return 0;
    }
    cout << (2*a[2]-a[0]-a[1]+1)/2+1 << endl;
} 