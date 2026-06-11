#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  ll m,k;
  cin >> m >> k;
  if(m==0){
    if(k==0){
      cout << "0 0" << endl;
    }else{
      cout << -1 << endl;
    }
    return 0;
  }
  if(m==1){
    if(k==0){
      cout << "1 0 0 1" << endl;
    }else{
      cout << -1 << endl;
    }
    return 0;
  }
  
  if(k>=(1<<m)){
    cout << -1 << endl;
    return 0;
  }
  
  ll i;
  if(k==0){
    for(i=(1<<m)-1;i>=0;i--){
      cout << i << ' ';
    }
    for(i=0;i<(1<<m);i++){
      cout << i << ' ';
    }
    return 0;
  }
  
  for(i=(1<<m)-1;i>=0;i--){
    if(i!=k){
      cout << i << ' ';
    }
  }
  cout << k << ' ';
  for(i=0;i<(1<<m);i++){
    if(i!=k){
      cout << i << ' ';
    }
  }
  cout << k << endl;
}