#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
//#define MOD 998244353
#define INF 1000000010
#define EPS 1e-9
#define F first
#define S second

#define debug(x) cout<<x<<endl;
#define repi(i,x,n) for(int i=x;i<n;i++)
#define rep(i,n) repi(i,0,n)
#define lp(i,n) repi(i,0,n)
#define repn(i,n) for(int i=n;i>=0;i--)
#define int long long
#define endl "\n"

typedef pair<int,int> PII;
typedef pair<int,string> PIS;
typedef pair<string,int> PSI;

map<int,int> prime_factor(int n){
  map<int,int> mp;
  for(int i=2;i*i<=n;i+=2){
    while(n%i==0){
      mp[i]++;
      n/=i;
    }
    if(i==2) i--;
  }
  if(n!=1) mp[n]=1;
  return mp;
}


signed main(){
  cin.tie(0);	
  ios::sync_with_stdio(false);
  int n;
  cin>>n;
  map<int,int> fac;
  repi(i,1,n){
    map<int,int> mp=prime_factor(i+1);
    for(auto itr=mp.begin();itr!=mp.end();itr++){
      fac[itr->F]+=itr->S;
    }
  }
  int two=0,four=0,fourteen=0,twofour=0,sevenfour=0;
  for(auto itr=fac.begin();itr!=fac.end();itr++){
    int num=itr->S;
    if(num>=2) two++;
    if(num>=4) four++;
    if(num>=14) fourteen++;
    if(num>=24) twofour++;
    if(num>=74) sevenfour++;
  }
  //cout<<two<<" "<<four<<endl;
  int ans=0;
  ans+=sevenfour;
  if(twofour!=0) ans+=twofour*(two-1);
  if(fourteen!=0) ans+=fourteen*(four-1);
  ans+=four*(four-1)*(two-2)/2;
  cout<<ans<<endl;
  

  return 0;
}
