#include <iostream>
#include <vector>
using namespace std;
int main(){
  int i,n;
  cin >> n;
  vector<char> s(n);
  for(i=0;i<n;i++) cin >> s[i];
  for(i=0;i<n;i++){
    if(s[i]=='Y'){
      cout << "Four" << "\n";
      return 0;
    }
  }
  cout << "Three" << "\n";
  return 0;
}