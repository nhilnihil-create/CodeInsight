#define rep(i,n) for (int i=0;i<n;i++)
#include <bits/stdc++.h>
#include <climits>
#include <iostream>
using namespace std;
typedef long long ll;


int main(){
 
  ll N,M,ans=0;
  cin >> N >> M;
  
  if(M<=N){
    cout << 0 << endl;
    return 0;
  }
  
  vector <ll> X(M);
  
  rep(i,M){
    cin >> X.at(i);
  }
  
  sort(X.begin(),X.end());
  
  /*if(N==1){
    cout << X.end() - X.begin() << endl;
    return 0;
  }*/
  
  vector <ll> dif(M-1);
  
  rep(i,M-1){
    dif.at(i)=X.at(i+1)-X.at(i);
  }
  
  sort(dif.begin(),dif.end());

  
  rep(i,M-N){
    ans+=dif.at(i);
  }
    
 
  
  cout << ans << endl;
  
  
  
  
}