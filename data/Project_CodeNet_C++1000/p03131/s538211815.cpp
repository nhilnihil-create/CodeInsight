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
int dx[]={0,1,0,-1,1,-1,-1,1};
int dy[]={1,0,-1,0,1,1,-1,-1};
const int MOD = 1e9+7;
const int INF = 1e18+10;

/*----------------------------------------------*/

signed main(){
  int k,a,b;
  cin>>k>>a>>b;
  if(b-a<=2){
    cout<<k+1<<endl;
    return 0;
  }
  int ans=1;
  ans+=min(k,a-1);
  k-=min(k,a-1);
  ans+=k/2*(b-a);
  k%=2;
  if(k>0) ans++;

  cout<<ans<<endl;

  return 0;
}
