//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ld long double
#define al(a) (a).begin(),(a).end()
#define mk make_pair
#define check cout<<"?"<<endl;

ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;

ll gcd(ll a,ll b){
    ll temp;
    while(b){
        temp=b;
        b=a%b;
        a=temp;
    }
    return a;
}

int main(){
    ll n,m; cin>>n>>m;
    string s,t; cin>>s>>t;
    ll g=gcd(n,m);
    ll ans=m*n/g;
    rep(i,g){
        if(s[n/g*i]!=t[m/g*i]) ans=-1;
    }
    cout<<ans<<endl;
}