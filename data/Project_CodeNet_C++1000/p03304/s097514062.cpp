#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep2(i,m,n) for(int (i)=(m);(i)<(n);(i)++)
const ll INF = 1LL<<60;
const ll MOD = 1e9+7;

double prob(ll n, ll d){
    if(d==0)return (double)1/n;
    else return (double)2*(n-d)/n/n;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n,m,d;cin>>n>>m>>d;
    cout<<setprecision(12)<<(m-1)*prob(n,d);
    return 0;
}