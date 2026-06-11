#include<bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c,z;
  cin >> a >> b >> c >> z;
  int an=0,bn=0,cn=0;
  int ans=0;
  for(int i=0;i<=a;i++){
    for(int j=0;j<=b;j++){
      for(int k=0;k<=c;k++){
        if(i*500+j*100+k*50==z)
          ans++;
      }
    }
  }
  cout << ans << endl;
}