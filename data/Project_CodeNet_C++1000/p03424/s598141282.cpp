#include <iostream>
#include <string>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int n;
  cin >> n;
  bool p,w,g,y = false;
  rep(i,n){
      string s;
      cin >> s;
      if(s=="P"){
          if (p==false){
              p=true;
          }
      }
      else if(s=="W"){
          if (w==false){
              w=true;
          }
      }
      else if(s=="G"){
          if (g==false){
              g=true;
          }
      }
      else{
          if (y==false){
              y=true;
          }
      }
  }
  int ans = 0;
  if (p) ++ans;
  if (w) ++ans;
  if (g) ++ans;
  if (y) ++ans;

  if (ans==3) cout<<"Three"<<endl;
  else cout<<"Four"<<endl;
}