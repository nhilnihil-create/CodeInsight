#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b,c;
  cin>>a>>b>>c;
  int dai=max({a,b,c});
  int shou=min({a,b,c});
  int naka=a+b+c-dai-shou;
  if((2*dai-shou-naka)%2==0){
    cout<<(2*dai-shou-naka)/2<<endl;
  }else{
    cout<<(2*dai-shou-naka)/2+2<<endl;
  }
  return 0;
}