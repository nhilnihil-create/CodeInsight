#include <bits/stdc++.h>
#define rep(i,n) for (int i= 0;i<(n);++i)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const long long INF = 1LL << 60;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
    ll n;cin>>n;
    vector<ll> d(n);rep(i,n)cin>>d[i];
    ll m;cin>>m;
    vector<ll> t(m);rep(i,m)cin>>t[i];
    multiset<ll> x;
    rep(i,n){
        x.insert(d[i]);
    }
    rep(i,m){
        if(x.count(t[i])){
            x.erase(x.find(t[i]));
        }
        else {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
    return 0;


}