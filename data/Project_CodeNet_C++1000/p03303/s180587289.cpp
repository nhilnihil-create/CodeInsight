#include<bits/stdc++.h>
#define Rep(i,n) for(int i=0;i<(n);++i)
using namespace std;

int main(){
  string s;cin >> s;
  int w,i=0;cin >> w;
  while(s.length() > i){
    cout << s[i];
    i += w;
  }
  cout << endl;
  return 0;
}