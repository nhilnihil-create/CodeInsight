#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define F first
#define S second

using namespace std;
typedef pair<int,int> P;
typedef vector<int> ivec;

const int MOD=1000000007;
int INF=100100100100100;
int a[100010];
int l[100010];
int r[100010];
signed main(){
  int n;cin>>n;
  int ans=0;
  rep(i,n)cin>>a[i];
  rep(i,n){
    if(i==0)l[0]=a[0];
    else l[i]=__gcd(l[i-1],a[i]);
  }
  for(int i=n-1;i>=0;i--){
    if(i==n-1)r[n-1]=a[n-1];
    else r[i]=__gcd(r[i+1],a[i]);
  }
  rep(i,n){
    if(i==0)ans=max(ans,r[1]);
    if(i==n-1)ans=max(ans,l[n-2]);
    else ans=max(ans,__gcd(l[i-1],r[i+1]));
  }
  cout<<ans<<endl;
  return 0;
}