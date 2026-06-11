#include <bits/stdc++.h>
using namespace std;

int main(){
  int X;
  cin>>X;
  bool flag=false;
  int ans;
  while(!flag){
    for (int b=1; b<=1000; b++){
      for (int p=2; p<=10; p++){
        if (X==pow(b,p)){
          flag=true;
          ans=pow(b,p);
        }
      }
    }
    X-=1;
  }
  cout<<ans<<endl;
}