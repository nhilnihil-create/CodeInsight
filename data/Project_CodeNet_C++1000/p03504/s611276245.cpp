#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(x) begin(x), end(x)
#define chmax(x,y) x = max(x,y)
using namespace std;
typedef long long ll;
typedef pair <int,int> P;

int a[35][100005];

int main(){
  int n,c;
  cin>>n>>c;
  rep(i,n){
    int s,t,c;
    cin>>s>>t>>c;
    c--;
    if(a[c][s]<0){
      a[c][s]++;
      a[c][t]--;
    }
    else if(a[c][t]>0){
      a[c][t]--;
      a[c][s]++;
    }
    else{
      a[c][s]++;
      a[c][t]--;
    }
  }
  int rec=0,ans=0;
  rep(i,100005){
    int p=0,m=0;
    rep(j,c){
      if(a[j][i]==1) p++;
      if(a[j][i]==-1) m++;
    }
    rec+=p;
    chmax(ans,rec);
    rec-=m;
  }
  cout<<ans<<endl;
  return 0;
}
