#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;i+=2)
using namespace std;

vector<int> divisor(int n){
  vector<int> res;
  for(int i=1;i*i<=n;i++){
    if(n%i==0){
      res.push_back(i);
      if(i!=n/i)res.push_back(n/i);
    }
  }
  return res;
}

int main(){
  int n;
  cin >> n;

  int ans=0;
  rep(i,n){
    vector<int> div=divisor(i);
    if(div.size()==8)ans++;
  }
  cout << ans << endl;
}