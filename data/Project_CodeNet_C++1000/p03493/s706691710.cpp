#include <iostream>

using namespace std;

int main(){
  string a;
  cin >> a;
  int ans = 0;
  for(int i=0;i<3;i++){
  if(a.at(i)=='1') ans++;
  }
  cout << ans;
}
