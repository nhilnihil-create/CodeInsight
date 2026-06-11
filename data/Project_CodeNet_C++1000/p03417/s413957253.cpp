#define rep(i,n) for (int i=0;i<n;i++)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  
  ll N,M;
  cin >> N >> M;
  
  if(N>=2 && M>=2){
   cout << (N-2)*(M-2) << endl;
  }else if(N==1 && M!=1){
    cout << M-2 << endl;
  }else if(N!=1 && M==1){
     cout << N-2 << endl;
  }else{
    cout << 1 << endl;
  }
  
  
  
  
}