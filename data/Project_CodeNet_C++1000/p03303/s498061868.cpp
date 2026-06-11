#include <bits/stdc++.h>
using namespace std;

int main(){
  string s; cin>>s;
  int w; cin>>w;
  int n = s.size();
  int i = 0;
  while(i<=n-1){
    cout<<s[i];
    i+=w;
  }
  cout << endl;
}