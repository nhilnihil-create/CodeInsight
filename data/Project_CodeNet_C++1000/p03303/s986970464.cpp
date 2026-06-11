#include <bits/stdc++.h>
using namespace std;
 
int main(){
  string s; cin >> s;
  int n; cin >> n;
  int count=0;
  for(int i=0;count<s.size();i++){
    cout <<s[count];
    count += n;
  }
  cout  << endl;
}