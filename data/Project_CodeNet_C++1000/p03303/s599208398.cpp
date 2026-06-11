#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  int w;
  cin >> s >> w;
  int n=s.size();
  for(int i=0;i<n;i++){
    if(i%w==0) cout << s[i];
  }
  cout << endl;
}