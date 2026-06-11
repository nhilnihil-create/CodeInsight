#pragma GCC optimize("O3")
#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
typedef  unsigned long long int ull;
typedef pair<ll,ll> P;
template<class T> using V=vector<T>; 
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
const ll inf=(1e18);
//const ll mod=998244353;
const ll mod=1000000007;
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
ll gcd(ll a,ll b) {return b ? gcd(b,a%b):a;}
ll lcm(ll c,ll d){return c/gcd(c,d)*d;}
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
int main(){
int n,k;
cin>>n>>k;
V<ll> a(n),d,sum(n+1,0);
for(int i=0;i<n;i++){
    cin>>a[i];
    sum[i+1]=a[i]+sum[i];
}
for(int i=0;i<n;i++){
    for(int j=i+1;j<=n;j++)d.push_back(sum[j]-sum[i]);
}
ll ans=0;
for(int i=60;i>=0;i--){
  //Aimax=10e9だが累積和の最大値が10e12であるため32では足りないことに気を付ける
    int cnt=0;
      for(int j=0;j<d.size();j++){
            if(d[j]&(1ll<<i))cnt++;
      }
    if(cnt>=k){
          V<ll> tmp;
    for(int j=0;j<d.size();j++){
         if(d[j]&(1ll<<i))tmp.push_back(d[j]);
      }
      d.clear();
      ans+=(1ll<<i);
      d=tmp;
      }
}
cout<<ans<<endl;
}
