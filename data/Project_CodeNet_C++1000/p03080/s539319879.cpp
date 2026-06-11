#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
typedef long long ll;


int main(void){
  int n,i,r,b;
  string s;
  
  cin >> n >> s;
  
  r=b=0;
  for (i=0;i<n;i++){
    if (s[i]=='R') r++;
    else b++;
  }
  
  if (r>b) cout << "Yes" << endl;
  else cout << "No" << endl;
  
  return 0;
}
