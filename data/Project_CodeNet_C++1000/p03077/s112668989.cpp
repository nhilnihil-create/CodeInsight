#include<bits/stdc++.h>
using namespace std;
const long long MOD = 1e9+7;
#define rep(i,n) for(int i=0;i<n;++i)
typedef long long int ll;
typedef unsigned long long ull;
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
typedef pair<ll,ll> P;


int main(){
    ll n,a,b,c,d,e;
    cin >> n >> a>>b >>c >> d>>e;
    vector<ll>box(6);
    rep(i,6)box[i]=0;
    box[0]=n;
    ll cnt=0;
    
    cout<< (ll)ceil((double)n/min({a,b,c,d,e}))+4 << endl;
    return 0;
}
