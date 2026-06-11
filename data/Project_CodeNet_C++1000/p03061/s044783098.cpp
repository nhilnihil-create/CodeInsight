#define _GLIBCXX_DEBUG
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
    int n;cin>>n;
    vector<int> x(n);
    rep(i,0,n) cin>>x[i];
    vector<int> a(n),b(n);
    a[0] = x[0];
    b[n-1] = x[n-1];
    rep(i,1,n){
        a[i] = __gcd(a[i-1],x[i]);
    }
    repp(i,n-2,0){
        b[i] = __gcd(b[i+1],x[i]);
    } 
    int ans = max(b[1],a[n-2]);
    rep(i,1,n-1){
        ans = max(ans,__gcd(a[i-1],b[i+1]));
    }
    cout<<ans<<endl;
}