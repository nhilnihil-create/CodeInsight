#include<bits/stdc++.h>
#include<iomanip>
using namespace std;
typedef long long ll;
typedef long  l;
typedef pair<int,int> P;
#define rep(i,n) for(int i=0;i<n;i++)
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
const double PI=3.141592653589;
const int INF=1000000007;
const ll LMAX=1000000000000001;
ll gcd(ll a,ll b){if(a<b)swap(a,b);ll c=a%b;while(c!=0){a=b;b=c;c=a%b;}return b;}
ll lcm(ll a,ll b){return a*b/gcd(a,b);}
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

int main(){
  int n; cin>>n;
  vector<vector<bool>> f(n,vector<bool>(10,0));
  vector<vector<int>> p(n,vector<int>(11,0));
  rep(i,n){
    rep(j,10){
      int F; cin>>F;
      if(F==1) f[i][j]=1;
    }
  }
  rep(i,n){
    rep(j,11) cin>>p[i][j];
  }

  int ans=-INF;
  for(int bit=1;bit<(1<<10);bit++){
    int sum=0;
    rep(i,n){
      int c=0;
      rep(j,10){
        if(f[i][j]&&((bit&(1<<j))!=0)) c++;
      }
      sum+=p[i][c];
    }
    ans=max(sum,ans);
  }
  cout<<ans<<endl;

  return 0;
}
