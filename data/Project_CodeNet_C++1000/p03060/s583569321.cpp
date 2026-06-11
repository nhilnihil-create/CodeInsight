//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define INF 100000000
#define rep(i,s,n) for (int i = (int)(s); i < (int)(n); i++)
#define repp(i,n,s) for (int i= (int)(n); i >= (int)(s); i--)
#define mp make_pair
ll mod = 1000000007;
ll mod2 = 998244353;

int main(){
	cin.tie(0);
    ios::sync_with_stdio(false);
    ll ans = 0;
    int n;cin>>n;
    vector<int> v(n),c(n);
    rep(i,0,n){
        int k;cin>>k;
        v[i] = k;
    }
    rep(i,0,n){
        int k;cin>>k;
        c[i] = k;
    }
    rep(i,0,n){
        if (v[i]>c[i]) ans+= v[i]-c[i];
    }
    cout<<ans<<endl;
}