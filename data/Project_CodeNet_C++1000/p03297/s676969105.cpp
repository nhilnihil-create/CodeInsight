#pragma GCC optimize("O3")
#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
using P=pair<ll,ll>;
template<class T> using V=vector<T>; 
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
const ll inf=(1e18);
const ll mod=998244353;
//const ll mod=1000000007;
ll GCD(ll a,ll b) {return b ? GCD(b,a%b):a;}
ll LCM(ll c,ll d){return c/GCD(c,d)*d;}
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
void pitsu(){
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a<b||b>d){
        cout<<"No"<<"\n";
        return ;
    }
    if(c>=b){
        cout<<"Yes"<<"\n";
        return;
    }
    ll g=GCD(b,d);
    ll MAX=(b-a%g+g-1)/g*g+a%g-g;
    if(MAX>c)cout<<"No"<<"\n";
    else cout<<"Yes"<<"\n";
}
int main(){
    int t;
    cin>>t;
    while(t--)pitsu();
}