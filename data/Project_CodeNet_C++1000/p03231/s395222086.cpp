#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll,ll>;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep2(i,m,n) for(int (i)=(m);(i)<(n);(i)++)
#define ALL(obj) (obj).begin(), (obj).end()
#define rALL(obj) (obj).rbegin(), (obj).rend()
const ll INF = 1LL<<60;
const ll MOD = 1e9+7;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n,m;cin>>n>>m;
    string s,t;cin>>s>>t;
    ll g = __gcd(n,m);
    bool flag = false;
    for(int i=0; i<g; i++){
        if(s[n*i/g]!=t[m*i/g])flag=true;
    }
    if(flag)cout<<-1<<endl;
    else cout<<n/g*m<<endl;


    return 0;
}