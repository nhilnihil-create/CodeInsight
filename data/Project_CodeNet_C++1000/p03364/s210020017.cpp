#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
typedef long long ll;
char s[610][610];
int map[305][305];

#define rep(i,n) for(ll i=0;i<n;++i)
#define rep1(i,n) for(ll i=1;i<=n;++i)
int main(){
  int n,x,y;
  char buf;
  cin>>n;
  rep(i,n){
    rep(j,n){
      cin>>buf;
      s[i][j]=buf;
      s[i+n][j]=buf;
      s[i][j+n]=buf;
      s[i+n][j+n]=buf;
      map[i][j]=0;
    }
  }
  int ans=0;
  rep(a,n){
      int check=0;
      rep(i,n){
	for(int j=i+1;j<n;j++){
	  if(s[i+a][j]!=s[j+a][i])goto FINE;
	}
      }
      ans+=n-a;
    FINE:;
  }
  rep1(b,n-1){
    int check=0;
    rep(i,n){
      for(int j=i+1;j<n;j++){
	if(s[i][j+b]!=s[j][i+b])goto FINE2;
      }
    }
    ans+=n-b;
  FINE2:;
  }
  cout<<ans<<endl;
  return 0;
}
