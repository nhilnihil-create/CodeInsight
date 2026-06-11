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
const ll mod=1000000007;
//const ll mod=998244353;
ll gcd(ll a,ll b) {return b ? gcd(b,a%b):a;}
ll lcm(ll c,ll d){return c/gcd(c,d)*d;}
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
int main(){
    int n;
    cin>>n;
    V<ll> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    reverse(all(a));
    ll ma=2,mi=2;
    for(int i=0;i<n;i++){
        if(ma/a[i]==(mi-1)/a[i]){
            cout<<-1<<endl;
            return 0;
            }
              mi=(mi+a[i]-1)/a[i]*a[i];
              ma=(ma/a[i]+1)*a[i]-1;
    }
    cout<<mi<<" "<<ma<<endl;
}
