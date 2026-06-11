#include<bits/stdc++.h>
using namespace std;

#define ld long double
#define ll long long
#define ALL(a)  (a).begin(),(a).end()
#define ALLR(a)  (a).rbegin(),(a).rend()
#define spa << " " <<
#define MP make_pair
ll MOD = 1e9+7;
//ll MOD = 998244353;
ll INF = 1e18;
void chmin(ll &a, ll b) { if (a > b) a = b; }
void chmax(ll &a, ll b) { if (a < b) a = b; }
void ans1(bool x){
  if(x) cout<<"Yes"<<endl;else cout<<"No"<<endl;}
void ans2(bool x){
  if(x) cout<<"YES"<<endl;else cout<<"NO"<<endl;}
void ans3(bool x){
  if(x) cout<<"Yay!"<<endl;else cout<<":("<<endl;}
void ans(bool x, ll y, ll z){
  if(x) cout<<y<<endl;else cout<<z<<endl;}   


int main(){
  ll i,j,o;
  ll result=0,buf=0,buf1=0,buf2=0,buf3=0,buf4=0;
  bool judge = true;
  ll n;cin>>n;
  vector<ll>a(n);
  for(i=0;i<n;i++)cin>>a[i];

  ll maxbuf=0,minbuf=0,maxn=0,minn=0;
  for(i=0;i<n;i++){
    if(maxbuf<a[i]){
      maxbuf=a[i];
      maxn=i;
    }
    if(minbuf>a[i]){
      minbuf=a[i];
      minn=i;
    }
  }
  vector<pair<ll,ll>> r;//最後r+1で取り出し
  if(abs(maxbuf)>=abs(minbuf)){
    for(i=0;i<n;i++){
      if(i!=maxn){
        r.push_back({maxn,i});
      }
    }
    for(i=0;i<n-1;i++){
      r.push_back({i,i+1});
    }
  }
  else if(abs(maxbuf)<abs(minbuf)){
    for(i=0;i<n;i++){
      if(i!=minn){
        r.push_back({minn,i});
      }
    }
    for(i=n-1;i>0;i--){
      r.push_back({i,i-1});
    }
  }

  cout<<r.size()<<endl;
  for(i=0;i<r.size();i++){
    cout<<r[i].first+1 spa r[i].second+1<<endl;
  }



  return 0;
}