#include <bits/stdc++.h>
using namespace std;
int a,b;
#define For(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n) For(i,0,n)

#define F first
#define S second
#define psb push_back
#define mkp make_pair
#define All(x) x.begin(),x.end()
#define nxp next_permutation

typedef double db;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll INF=1e17;

int main(){
  int n=100001;
  vector<int> v(n,0);
  for(int i=2;i<=n;i++){
  v[i]=1;
  }
  for(int i=2;i<=n;i++){
    if(v[i]){for(int j=i*2;j<=n;j+=i)v[j]=0;}
  }
vector<int> a(n,0);
  for(int i=2;i<=n;i++){
  a[i]=i;
  if(v[i]&&v[(a[i]+1)/2])a[i]=1;
    else a[i]=0;
  }
  vector<int> s(n+2,0);
  s[0]=0;
  for(int i=0;i<=n;i++)s[i+1]=s[i]+a[i];
  int q;
  cin>>q;
  rep(i,q){
  int l,r;
    cin>>l>>r;
    cout<<s[r+1]-s[l]<<endl;
  }

  return 0;
}