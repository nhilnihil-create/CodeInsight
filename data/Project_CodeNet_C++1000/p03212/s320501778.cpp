#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FOR(i,a,b) for(int i=(a); i<=(b); i++)
#define rep(i,n) for(int i = 0; i < (n); i++)
#define chmin(a,b) if((a)>(b)) (a)=(b);
#define chmax(a,b) if((a)<(b)) (a)=(b);
#define vi vector<int>
#define pii pair<int,int>
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define pb push_back
#define pf push_front
int gcd(int a,int b){/*a>=0,b>=0,￢(a=b=0)*/
  while(min(a,b)>0){if(a<b)swap(a,b);a%=b;}return max(a,b);
}
int dx[]={1,0,-1,0,1,-1,-1,1};
int dy[]={0,1,0,-1,1,1,-1,-1};
const int MOD = 1e9+7;
const int INF = 1e18+10;

/*----------------------------------------------*/
int n;
vi a;

bool check(int k,int keta){
  vi ok(3,0);
  rep(i,keta){
    int z=k%10;
    rep(j,3){
      if(z==3+j*2) ok[j]=1;
    }
    k/=10;
  }
  if(ok[0]==1&&ok[1]==1&&ok[2]==1) return true;
  else return false;
}

void dfs(int k,int keta){
  if(k>n) return;
  if(check(k,keta)) a.pb(k);
  rep(i,3){
    dfs(10*k+i*2+3,keta+1);
  }
}

signed main(){
  cin>>n;
  dfs(0,0);
  cout<<a.size()<<endl;

  rep(i,a.size()){
  }
  return 0;
}
