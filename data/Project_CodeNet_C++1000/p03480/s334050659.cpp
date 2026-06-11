#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
  int ret=100000000;
  string s;
  cin >> s;
  int n=s.length();
  for(int i=1; i<n; i++){
    if(s[i-1]!=s[i]){
      ret=min(ret, max(i, n-i));
    }
  }
  if(ret==100000000)ret=n;
  cout << ret;
  return 0;
}
