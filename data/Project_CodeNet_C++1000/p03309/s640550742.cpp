#include<bits/stdc++.h>
#define INFTY 10000000000
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
const int MOD=1000000007;
const int di[4] = {-1,0,1,0};
const int dj[4] = {0,-1,0,1};
ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}


int main(){
    int n;cin>>n;
    vector<ll> a(n);

    rep(i,n){
        ll num;cin >> num;
        a[i] = num-(i+1);
    }
    sort(a.begin(),a.end());

    ll ans=0;
    rep(i,n){
        ans += abs(a[i]-a[n/2]);
    }
cout<<ans<<endl;
    return 0;
}