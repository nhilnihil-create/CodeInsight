#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  scanf("%d",&n);
  int ans=0;
  for(int i=1;i<=n;i+=2){
    int z=0;
    for(int j=1;j<=i;j++){
      if(i%j==0)
        z++;
    }
    if(z==8)
      ans++;
  }
  cout << ans << endl;
  return 0;
}