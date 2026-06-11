#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
template <class T> inline bool chmin(T &a, T b) {if (a > b){a = b;return true;}return false;}
template <class T> inline bool chmax(T &a, T b) {if (a < b){a = b;return true;}return false;}

vector<ll> ab;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll x,y,z,k;cin>>x>>y>>z>>k;
    // priority_queue<ll> pq;
    vector<ll> a(x),b(y),c(z);
    rep(i,x) cin>>a[i];
    rep(i,y) cin>>b[i];
    rep(i,z) cin>>c[i];
    rep(i,x){
        rep(j,y){
            ab.emplace_back(a[i]+b[j]);
        }
    }
    sort(ab.rbegin(), ab.rend());
    vector<ll> zz;
    for(ll i=0; i<k && i<ab.size(); i++){
        rep(j, z){
            zz.emplace_back(ab[i]+c[j]);
        }
    }
    sort(zz.rbegin(), zz.rend());
    rep(i,k){
        cout<<zz[i]<<endl;
    }
    return 0;
    
}