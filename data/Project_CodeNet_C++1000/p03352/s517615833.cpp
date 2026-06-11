#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i < (n); i++)
using namespace std;
using ll = long long;


int main(){
  int X; cin>>X;
  if(X==1){
    cout <<1 << endl;
    return 0;
  }
  
  int ans=0;
  for(int i=2; i*i<=X; i++){
    int j=i;
    while(j*i<=X){
      j *=i;
      ans = max(j,ans);
    }
  }
  cout << ans << endl;
}
