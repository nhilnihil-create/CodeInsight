#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;

#define fi first
#define se second
#define repl(i,a,b) for(ll i=(ll)(a);i<(ll)(b);i++)
#define rep(i,n) repl(i,0,n)
#define each(itr,v) for(auto itr:v)
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout<<#x"="<<x<<endl
#define mmax(x,y) (x>y?x:y)
#define mmin(x,y) (x<y?x:y)
#define maxch(x,y) x=mmax(x,y)
#define minch(x,y) x=mmin(x,y)
#define uni(x) x.erase(unique(all(x)),x.end())
#define exist(x,y) (find(all(x),y)!=x.end())
#define bcnt __builtin_popcount

#define INF INT_MAX/3

string s;
ll x,y;
vector<ll> a,b;
bool dp1[2][20011],dp2[2][20011];

int main(){
  cin>>s>>x>>y;
  s+="T";
  ll n=s.size();
  ll crt=0,sum=0;
  rep(i,n){
    if(s[i]=='T'){
      if(crt==0)a.push_back(sum);
      else b.push_back(sum);
      sum=0;
      crt=1-crt;
    }else{
      sum++;
    }
  }

  crt=0;
  ll nxt=1;
  dp1[crt][10000]=true;
  rep(i,a.size()){
    memset(dp1[nxt],0,sizeof(dp1[nxt]));
    rep(j,20001){
      if(!dp1[crt][j])continue;
      if(i==0){
        if(j+a[i]<=20000)dp1[nxt][j+a[i]]=true;
      }else{
        if(j+a[i]<=20000)dp1[nxt][j+a[i]]=true;
        if(j-a[i]>=0)dp1[nxt][j-a[i]]=true;
      }
    }
    swap(crt,nxt);
  }

  if(!dp1[crt][x+10000]){
    cout<<"No"<<endl;
    return 0;
  }

  crt=0;
  nxt=1;
  dp2[crt][10000]=true;
  rep(i,b.size()){
    memset(dp2[nxt],0,sizeof(dp2[nxt]));
    rep(j,20001){
      if(!dp2[crt][j])continue;
      if(j+b[i]<=20000)dp2[nxt][j+b[i]]=true;
      if(j-b[i]>=0)dp2[nxt][j-b[i]]=true;
    }
    swap(crt,nxt);
  }

  if(!dp2[crt][y+10000]){
    cout<<"No"<<endl;
    return 0;
  }
  cout<<"Yes"<<endl;

  return 0;
}
