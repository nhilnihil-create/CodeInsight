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

/*--------------------------------------------------------------------*/


signed main(){
  int n,m;
  cin>>n>>m;

  vi yaku;
  for(int i=1;i*i<=m;i++){
    if(m%i==0){
      yaku.pb(i);
      if(i*i!=m) yaku.pb(m/i);
    }
  }
  sort(all(yaku));

  // rep(i,yaku.size()) cout<<yaku[i]<<endl;
  int mx=0;
  for(int g:yaku){
    int z=m-g*n;
    if(z<0) continue;
    if(z%g==0) mx=g;
    // printf("%d:%d\n",g,z);
  }
  cout<<mx<<endl;
  return 0;
}
