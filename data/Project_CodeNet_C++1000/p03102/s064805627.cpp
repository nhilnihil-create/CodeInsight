#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(v) v.begin(), v.end()
typedef long long ll;

#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m,c;
  cin>>n>>m>>c;
  
  int B[m];
  rep(i,m) cin>>B[i];
  
  int cnt=0,x;
  rep(i,n){
    int ans=0;
    rep(j,m){
      cin>>x;
      ans+=x*B[j];
    }
    ans+=c;
    if(ans>0) cnt++;
  }
  
  cout<<cnt<<endl;
 
  return 0;
}