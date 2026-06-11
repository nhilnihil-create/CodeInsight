#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i=0; i<(n); i++)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
int main(){
    ll a,b,c; cin>>a>>b>>c;
    ll k; cin>>k;
    ll res;
    if(k%2==0) res=a-b;
    else res=b-a;
    if(abs(res)>1e18) cout<<"Unfair"<<endl;
    else cout<<res<<endl;
    return 0;
}