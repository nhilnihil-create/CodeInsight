#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<cmath>
#include<cstdio>
#include<tuple>
#include<bitset>

using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define ALL(x) x.begin(),x.end()
#define ll long long
typedef pair<int,int> P;
const int inf=1000000007;
const int MOD=1000000007;
signed main(){
  int n;cin>>n;
  vector<int> a(n);
  vector<int> b(n);
  vector<P> sub(n);
  rep(i,n)cin>>a[i];
  rep(i,n)cin>>b[i];
  rep(i,n){
    sub[i].first=a[i]-b[i];
    sub[i].second=i;
  }
  sort(ALL(sub));
  int j=n;
  rep(i,n){
    if(sub[i].first>=0){
      j=i;
      break;
    }
  }
  if(j==0){
    cout<<0<<endl;
    return 0;
  }
  if(j==n){
    cout<<-1<<endl;
  }
  vector<int> pos(n-j,0);
  vector<int> neg(j,0);
  pos[n-j-1]=sub[n-1].first;
  neg[0]=sub[0].first;
  rep1(i,j-1){
    neg[i]=neg[i-1]+sub[i].first;
  }
  int t=neg[j-1]*(-1);
  int res=n;
  for(int i=n-2;i>=j;--i){
    pos[i-j]=pos[i-j+1]+sub[i].first;
    if(pos[i-j+1]>=t){
      res=j+n-1-i;
      break;
    }
  }
  if(pos[0]<t&&res==n){
    res=-1;
  }
  cout<<res<<endl;
  return 0;
}
