#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int n,k;
  cin >> n >> k;
  ll ans=0;
  
  for(int b=1;b<=n;b++){
    int p=n/b;
    int r=n%b;
    ans += p * max(0,b-k);
    ans += max(0,r-k+1);
  }
  
  if(k == 0){
    cout << ans - n<< endl;
  }else{
    cout << ans << endl;
  }
  
  return(0);
}