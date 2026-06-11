#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (long long i = 0; i < (long long) (n); i++)
#define Rep(i,n,m) for (long long i = n; i < (long long) (m); i++)
using ll=long long;
using vi = vector<int>;
using vll = vector<ll>;

const int mod = 1000000007;
// const int mod = 998244353;

int main(){
    long long n;
    cin>>n;
    vll vec(n);
    rep(i,n){cin>>vec.at(i);}
    sort(vec.begin(),vec.end());
    ll ans;
    ans=vec.at(0);
    rep(i,n){ans=gcd(ans,vec.at(i));}
    cout<<ans;

}
