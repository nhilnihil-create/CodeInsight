#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    int n;cin>>n;
    map<ll,ll> mp;
    ll tmp=0;
    ll res=0;
    rep(i,n){
        ll a;cin>>a;
        tmp+=a;
        res+=mp[tmp];
        mp[tmp]++;
    }
    res+=mp[0];
    cout<<res<<endl;
}