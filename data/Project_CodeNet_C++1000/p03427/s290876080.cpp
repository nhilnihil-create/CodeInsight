#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
  ll n;
  cin >> n;
  int k;
  for(int i=1;i<=16;i++){
    if(n==pow(10,i)){
      cout << 9*i << endl;
      return 0;
    }
    else if(n<pow(10,i)){
      k=i;
      break;
    }
  }
  int b=n/pow(10,k-1);
  int c=(n+1)/pow(10,k-1);
  if(k==1)
    cout << n << endl;
  else if(b<c){
    int ans=n/pow(10,k-1);
    ans=ans+9*(k-1);
    cout << ans << endl;
  }
  else{
    int ans=n/pow(10,k-1)-1;
    ans=ans+9*(k-1);
    cout << ans << endl;
  }
}

