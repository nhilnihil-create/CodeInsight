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
  int n,m;
  cin>>n>>m;
  priority_queue<P,vector<P>,greater<P>> q;
  ll a,b;
  rep(i,n){
    cin>>a>>b;
    q.push(P(a,b));
  }
  ll ans=0;
  while(m>0){
    P k=q.top();q.pop();
    if(m-k.se>=0) ans+=k.fi*k.se;
    else ans+=m*k.fi;
    m-=k.se;
  }
  
  cout<<ans<<endl;
}