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


signed main(){
  cin.tie(0);	
  ios::sync_with_stdio(false);
  int n,q;
  cin>>n>>q;
  string s;
  cin>>s;
  char t[q],d[q];
  rep(i,q){
    cin>>t[i]>>d[i];
  }
  s="!"+s;
  s=s+"!";
  int ll,rr;
  int l=0,r=n+1;
  int mid=(l+r)/2;
  while(l!=r){
    int now=mid+1;
    bool flag=true;
    rep(i,q){
      if(s[now]==t[i]){
	if(d[i]=='L') now--;
	else now++;
      }
      if(now==0){
	flag=false;
	break;
      }
    }
    if(flag) r=mid;
    else l=mid+1;
    mid=(l+r)/2;
  }
  ll=mid;
  l=0;r=n+1;mid=(l+r)/2;
  while(l!=r){
    int now=mid;
    bool flag=true;
    rep(i,q){
      if(s[now]==t[i]){
	if(d[i]=='L') now--;
	else now++;
      }
      if(now==n+1){
	flag=false;
	break;
      }
    }
    if(flag) l=mid+1;
    else r=mid;
    mid=(l+r)/2;
  }
  rr=mid;
  //cout<<ll<<" "<<rr<<endl;
  cout<<max((int)0,rr-ll-1)<<endl;

  return 0;
}
