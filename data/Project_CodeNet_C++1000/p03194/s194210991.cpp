#include<bits/stdc++.h>
using namespace std;

#define ALL(a)  (a).begin(),(a).end()
#define ALLR(a)  (a).rbegin(),(a).rend()
#define spa << " " <<
#define MP make_pair
#define test cout<<"test"<<endl;
#define fi first
#define se second
typedef long long ll;
typedef long double ld;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const ll INF = 1e18;
const ll zero=0;
using P = pair<ll, ll>;
void chmin(ll &a,ll b){if(a>b)a=b;}
void chmax(ll &a,ll b){if(a<b)a=b;}
void pmod(ll &a,ll b){a=(a+b)%MOD;}
void pmod(ll &a,ll b,ll c){a=(b+c)%MOD;}
void qmod(ll &a,ll b){a=(a*b)%MOD;}
void qmod(ll &a,ll b,ll c){a=(b*c)%MOD;}
void ans1(bool x){if(x) cout<<"Yes"<<endl;else cout<<"No"<<endl;}
void ans2(bool x){if(x) cout<<"YES"<<endl;else cout<<"NO"<<endl;}
void ans3(bool x){if(x) cout<<"Yay!"<<endl;else cout<<":("<<endl;}
void ans(bool x,ll y,ll z){if(x)cout<<y<<endl;else cout<<z<<endl;}
void ans(bool x,string y,string z){if(x)cout<<y<<endl;else cout<<z<<endl;}   
ll gcd(ll x,ll y){ll r;while((r=x%y)!=0){x=y;y=r;}return y;}

map<ll,ll> factoring(ll n){ 
  ll buf=n;
  map<ll,ll>ret;
  ll i,j;
  for(i=2;buf!=1&&i*i<=n;i++){
    for(j=0;buf%i==0;j++){
      buf/=i;
    }
    if(i>0)ret.emplace(i,j);
  }
  if(buf!=1)ret.emplace(buf,1);
  return ret;
}

int main(){
  ll i,j,o;
  ll res=0,res1=INF,res2=-INF,buf=0,buf1=0,buf2=0,buf3=0,buf4=0,sum=0;
  bool judge = true;
  ll n,p;cin>>n>>p;
  map<ll,ll>q=factoring(p);
  //cout<<q.size()<<endl;
  res=1;
  for(auto z:q){
    for(i=0;i<z.se/n;i++)res*=z.fi;
  }
  cout<<res<<endl;

  return 0;
}