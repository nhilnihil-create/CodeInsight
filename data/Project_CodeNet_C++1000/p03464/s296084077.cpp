#include <bits/stdc++.h>
#define rep(a,n) for (ll a = 0; a < (n); ++a)
using namespace std;
typedef long long ll;
using ll = long long;
typedef pair<ll,ll> P;
typedef pair<P,ll> PP;
//using Graph = vector<vector<ll> >;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1e9;

//input
ll k;
vector<ll>a;

int main(){
    //input
    cin >> k;
    a.resize(k);
    rep(i,k)cin>>a[k-1-i];

    vector<ll>l(k+1),r(k+1);
    l[0]=2;r[0]=2;
    for(int i=1;i<=k;i++){
        ll x = (l[i-1]+a[i-1]-1)/a[i-1]*a[i-1];
        ll y = r[i-1]/a[i-1]*a[i-1];
        if(x>y){
            cout << -1 << endl;
            return 0;
        }
        l[i]=(l[i-1]+a[i-1]-1)/a[i-1]*a[i-1];
        r[i]=r[i-1]/a[i-1]*a[i-1]+a[i-1]-1;
    }
    cout << l[k] << ' ' << r[k] << endl;

    return 0;
}
