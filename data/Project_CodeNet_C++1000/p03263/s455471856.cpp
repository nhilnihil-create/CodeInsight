#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

int main(){
  int h,w;
  cin>>h>>w;
  int a[h][w];
  rep(i,0,h){
    rep(j,0,w){
      cin>>a[i][j];
    }
  }
  int b[h*w][4];
  int ans=0;
  rep(i,0,h){
    rep(j,0,w-1){
      if(a[i][j]%2!=0){
        a[i][j]--;
        a[i][j+1]++;
        b[ans][0]=i;
        b[ans][1]=j;
        b[ans][2]=i;
        b[ans][3]=j+1;
        ans++;
      }
    }
  }
  rep(i,0,h-1){
    if(a[i][w-1]%2!=0){
      a[i][w-1]--;
      a[i+1][w-1]++;
      b[ans][0]=i;
      b[ans][1]=w-1;
      b[ans][2]=i+1;
      b[ans][3]=w-1;
      ans++;
    }
  }
  cout<<ans<<endl;
  rep(i,0,ans){
    cout<<b[i][0]+1<<" "<<b[i][1]+1<<" "<<b[i][2]+1<<" "<<b[i][3]+1<<endl;
  }
}