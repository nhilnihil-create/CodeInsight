#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,k;
  cin >> n >> k;
  string s;
  cin >> s;
  for(int i=0;s[i];i++){
    if(i+1==k){
      s[i]+=32;
    }
  }
  cout << s << endl;
  return 0;
}