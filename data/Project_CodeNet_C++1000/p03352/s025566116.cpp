#include <bits/stdc++.h>
using namespace std;
int main() {
  int x,ans=1; cin>>x;
  for(int b=2; b<=x; b++){
    int tmp=b*b;
    while(tmp<=x){
      ans=max(ans,tmp);
      tmp*=b;
    }
  }
  cout<<ans;
}