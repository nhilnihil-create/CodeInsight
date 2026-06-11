#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(v) v.begin(), v.end()
typedef long long ll;

#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  
  bool b=false;
  rep(i,26){
    rep(j,15){
      if(4*i+7*j==n) b=true;
    }
  }
  if(b) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
  
  return 0;
}