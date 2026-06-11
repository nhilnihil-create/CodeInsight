#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1000000007;


int main() {
  int n;
  cin >> n;
  int ans=0;
  if(n<105){
    cout << ans << endl;
    return 0;
  }
  else{
    for(int i=105;i<=n;i=i+2){
      int t=0;
      for(int j=1;j<=pow(i,0.5);j++){
        if(i%j==0)
        t++;
      }
      if(t==4)
      ans++;
    }
  }
  cout << ans << endl;
}

