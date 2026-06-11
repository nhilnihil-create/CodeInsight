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
  int n;
  cin>>n;
  int a[n],b[n],c[n];
  int sum=0;
   int ans=0;
  rep(i,n){
    cin>>a[i];
  }
  rep(i,n){
    cin>>b[i];
    c[i]=a[i]-b[i];
    if(b[i]>a[i]){
      sum+=b[i]-a[i];
      ans++;
    }
  }
  if(sum==0){
    cout<<0<<endl;
    return 0;
  }
  sort(c,c+n);
  repn(i,n-1){
    if(c[i]<=0){
      cout<<-1<<endl;
      return 0;
    }
    else{
      sum-=c[i];
      ans++;
      if(sum<=0){
	cout<<ans<<endl;
	return 0;
      }
    }
  }
      

  return 0;
}
