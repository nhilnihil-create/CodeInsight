#include <iostream>

using namespace std;

int main(){
  string a,b;
  cin >> a >> b;
  int ans = 0;
  for(int i=0;i<3;i++){
  if(a.at(i)!=b.at(2-i)) ans=1;
  }
  if(ans) cout << "NO";
  else cout << "YES";
}
