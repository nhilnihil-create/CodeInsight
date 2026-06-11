#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(v) v.begin(), v.end()
typedef long long ll;

#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,T;
  cin>>n>>T;
  
  int c,t;
  int mi=1e9;
  rep(i,n){
    cin>>c>>t;
    if(t<=T && c<mi) mi=c;
  }
  
  if(mi==1e9) cout<<"TLE"<<endl;
  else cout<<mi<<endl;
  
  return 0;
}