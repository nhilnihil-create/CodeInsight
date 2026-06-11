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
    int n,k;cin>>n>>k;
    vector<ll> h(n);
    rep(i,n)cin>>h[i];
    sort(h.begin(),h.end());
    ll mn = 10000000000;
    rep(i,n-k+1){
        if(mn > h[i+k-1]-h[i]){
            mn = h[i+k-1]-h[i];
        }
    }
    cout<<mn<<endl;
    return 0;
}