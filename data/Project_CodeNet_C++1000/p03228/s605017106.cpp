#include <bits/stdc++.h>

using ll = long long;
using namespace std;
const int INFint = 1e9+1;
const ll INFll = (ll)1e18+1;
ll MOD=1e9+7;

int main(){
  int A,B,K;
  cin>>A>>B>>K;
  for(int i(0);i<K;i++){
    if(i%2==0){
      if(A%2==1){
        A -= 1;
      }
      B += A/2;
      A/=2;
    }else{
      if(B%2==1) B-=1;
      A+=B/2;
      B/=2;
    }
  }
  cout << A << " " << B << endl;
  return 0;
}

