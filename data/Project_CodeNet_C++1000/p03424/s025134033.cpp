#include <iostream>
#include <string>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int n;
  cin >> n;
  bool y = false;
  rep(i,n){
      string s;
      cin >> s;
      if(s=="Y"){
          y=true;
          }
      }
  if (y) cout<<"Four"<<endl;
  else cout<<"Three"<<endl;
}