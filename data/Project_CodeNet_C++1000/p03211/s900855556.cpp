#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define rep(i, n) for (int i = 0; i < (int)(n); i++)


int main(){
  string S; cin>>S;
  int ans=INF;
  rep(i,S.length()-2){
    int a[3];
    int X=0;
    rep(j,3){
      a[j]=S[i+j]-'0';
      X+=pow(10,2-j)*a[j];
    }
    ans=min(ans,abs(X-753));
  }
  cout<<ans<<endl;
  return 0;
}
    
