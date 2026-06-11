#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
template <typename T> bool chmax(T &u, const T z) { if (u < z) {u = z; return true;} else return false; }
template <typename T> bool chmin(T &u, const T z) { if (u > z) {u = z; return true;} else return false; }
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long 
typedef pair<ll, ll> P;
const ll INF=1LL<<60;
ll gcd(ll x,ll y){return y? gcd(y,x%y) :x;}

int main(){
    int n;
    ll h;
    cin>>n>>h;
    vector<ll>a(n),b(n+1);
    rep(i,n)cin>>a[i]>>b[i];
    sort(a.rbegin(),a.rend());
    sort(b.rbegin(),b.rend());
    ll cnt=0;
    rep(i,n+1){
        cnt++;
        if(a[0]>=b[i]){
            ll kazu=h/a[0];
            if(h%a[0]!=0)kazu++;
            cnt+=kazu-1;
            break;
        }else h-=b[i];
        if(h<=0)break;
    }
    cout<<cnt<<endl;
}