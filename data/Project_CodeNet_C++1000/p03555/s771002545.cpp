#include <iostream>
#include <vector>
using namespace std;
int main(){
  int i;
  vector<char> v(6);
  for(i=0;i<6;i++) cin >> v[i];
  if(v[0]==v[5]&&v[1]==v[4]&&v[2]==v[3]) cout << "YES" << "\n";
  else cout << "NO" << "\n";
  return 0;
}