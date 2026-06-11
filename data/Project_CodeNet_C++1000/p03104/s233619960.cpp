#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define Rep(i,s,n) for(int i=s;i<n;i++)
#define per(i,s,n) for(int i=n-1;i>=s;i--)
#define fi first
#define se second
#define all(c) c.begin(),c.end()
typedef long long int ll;
typedef pair<ll, ll> P;
typedef long double ld;
void Ans(bool x){if(x) cout<<"Yes"<<endl;else cout<<"No"<<endl;}

const ll INF=1001001001;
const ll mod=1000000007;

int main(){
  ll a,b;
  cin>>a>>b;
  ll c;
  if(a%2==0&&b%2==0){
    c=(b-a)/2;
    ll ans;
    if(c%2==0) ans=0;
    else ans=1;
    if(b%2==ans) ans=b-ans;
    else ans=b+ans;
    cout<<ans<<endl;
  }
  
  else if(a%2==0&&b%2==1){
    c=(b-a+1)/2;
    if(c%2==0) cout<<0<<endl;
    else cout<<1<<endl;
  }
  
  else if(a%2==1&&b%2==0){
    c=(b-a-1)/2;
    ll ans;
    if(c%2==0) ans=0;
    else ans=1;
    ll now=0;
    ll n=1;
    while(a>0||b>0){
      if(a%2!=b%2) now+=n;
      a/=2;
      b/=2;
      n*=2;
    }
    if(now%2==ans) ans=now-ans;
    else ans=now+ans;
    cout<<ans<<endl;
  }
  
  else if(a%2==1&&b%2==1){
    c=(b-a)/2;
    ll ans;
    if(c%2==0) ans=0;
    else ans=1;
    if(a%2==ans) ans=a-ans;
    else ans=a+ans;
    cout<<ans<<endl;
  }
}