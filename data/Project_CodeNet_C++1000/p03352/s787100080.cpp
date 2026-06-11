#include <bits/stdc++.h>
using namespace std;

int main() {
  int x;
  cin>>x;
  int ans=1;
  for(int i=1;i<=x;i++){
    for(int b=2;b<=10;b++){
      int c=pow(i,b);
      if(c<=x) ans=max(ans,c);
    }
  }
  cout<<ans<<endl;
}
