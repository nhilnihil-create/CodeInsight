#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;

int main(){
  ll A,B,K;
  cin >> A >> B >> K;
  rep(i,K){
    if(i%2==0){
      if(A%2==1) A--;
      A/=2;
      B+=A;
    }
    else{
      if(B%2==1) B--;
      B/=2;
      A+=B;
    }
  }
  cout << A << " " << B;
  return 0;
}