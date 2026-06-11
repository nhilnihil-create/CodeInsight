// lcmとか__builtin_popcountとかはg++ -std=c++17 default.cppみたいなかんじで

#include <bits/stdc++.h>
#define mod 1000000007
#define INF LLONG_MAX
#define ll long long
#define ln cout<<endl
#define Yes cout<<"Yes"<<endl
#define NO cout<<"NO"<<endl
#define YES cout<<"YES"<<endl
#define No cout<<"No"<<endl
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
#define rep(i,n) REP(i,0,n)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
using namespace std;
ll dx[4]={1,0,-1,0};
ll dy[4]={0,1,0,-1};

int main() {
    cin.tie(0);
   	ios::sync_with_stdio(false);

    ll a,b,c,d,m,n,maxi=0,f=0,mini=INF,sum=0;
    string str;
    cin>>n;
    set<pair<ll,ll>> p;
    a=n;

    if(n%2)n--;
    n/=2;
    for(ll i=1;i<=n;i++){
        p.insert(make_pair(i,n*2+1-i));
        //cout<<i<<" "<<n*2+1-i<<endl;
    }
    for(ll i=1;i<=n*2;i++){
        for(ll j=i+1;j<=n*2;j++){
            pair<ll,ll> p1=make_pair(i,j);
        if(p.find(p1)==p.end()) sum++;
        }
    }
    if(a%2){
        for(ll i=1;i<a;i++) sum++;
    }

    cout<<sum<<endl;
    for(ll i=1;i<=n*2;i++){
        for(ll j=i+1;j<=n*2;j++){
            pair<ll,ll> p1=make_pair(i,j);
        if(p.find(p1)==p.end()) cout<<i<<" "<<j<<endl;
        }
    }
    if(a%2){
        for(ll i=1;i<a;i++) cout<<i<<" "<<a<<endl;
    }



    return 0;
}
