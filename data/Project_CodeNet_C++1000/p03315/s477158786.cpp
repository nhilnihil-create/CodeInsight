#include <iostream>
#include <string>
using namespace std;
int main(){
  int ans = 0;
  string S;
  cin >> S;
  for(auto& i:S){
    if(i == '+') ans++;
    else ans--;
  }
  cout << ans << endl;
}

