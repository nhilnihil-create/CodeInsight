#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    ll n;cin>>n;
    vector<pair<ll,ll>> t(n);
    vector<ll> a(n),b(n);
    rep(i,n){
        cin>>a[i]>>b[i];
        t[i].first=a[i]+b[i];
        t[i].second=i;
    }
    sort(t.rbegin(),t.rend());
    ll res=0;
    rep(i,n){
        int id=t[i].second;
        if(i%2==0)res+=a[id];
        else res-=b[id];
    }
    cout<<res<<endl;
}