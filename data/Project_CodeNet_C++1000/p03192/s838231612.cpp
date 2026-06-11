#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
typedef long long ll;


int main(void){
  int i,ans=0;
  string n;
  
  cin >> n;
  
  for (i=0;i<4;i++){
    if (n[i]=='2') ans++;
  }
  
  cout << ans << endl;
  
  return 0;
}