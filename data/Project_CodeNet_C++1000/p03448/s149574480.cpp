#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b,c,x;
  cin>>a>>b>>c>>x;
  int ans=0;
  int g=min(a,x/500);
  for(int i=0;i<=g;i++){
    int nokori=x-500*i;
    int h=min(b,nokori/100);
    for(int j=0;j<=h;j++){
      int nokoria=nokori-100*j;
      nokoria/=50;
      if(nokoria<=c) ans++;
    }
  }
  cout<<ans<<endl;
}
