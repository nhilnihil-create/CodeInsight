#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define pb push_back
#define mt make_tuple
#define ALL(a) (a).begin(),(a).end()
#define FST first
#define SEC second
#define DEB cerr<<"!"<<endl
#define SHOW(a,b) cerr<<(a)<<" "<<(b)<<endl
#define vi vector<int>

using ll = long long;
const int INF = (INT_MAX/2);
const ll LLINF = (LLONG_MAX/2);
const double eps = 1e-8;
const ll DIV =1e9+7;
//const double PI = M_PI;
inline ll pow(ll x,ll n,ll m){ll r=1;while(n>0){if((n&1)==1)r=r*x%m;x=x*x%m;n>>=1;}return r%m;}
inline ll lcm(ll d1, ll d2){return d1 / __gcd(d1, d2) * d2;}
inline ll inv(ll x, ll div){return pow(x, div - 2, div);}
#define chmax(a,b) a=max(a,b)
int gcj_out_cnt = 1;
#define gcj_put cout<<"Case #"<<gcj_out_cnt++<<": ";

/*Coding Space*/
ll a[1000001];
ll b[1000001];
tuple<ll,ll> c[1000001];
int main(){
  int n;  cin >> n;
  rep(i,n){
    cin >> a[i] >> b[i];
    c[i] = tuple<ll,ll>{-(a[i] + b[i]), i};
  }
  sort(begin(c),end(c));
  ll av = 0;
  ll bv = 0;
  rep(i,n){
    int value, index; tie(value,index) = c[i];
    if(i%2 == 0){
      av += a[index];
    }else{
      bv += b[index];
    }
    //cerr << index << endl;
  }
  cout << av - bv << endl;
}
