#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a;
  cin >> a;
  int B = 0;
  int R = 0;
  string s;
  cin >> s;
  for(int i=0;i<a;++i){
    if(s.at(i) == 'B') B++; 
    else R++;
  }
  if(B >= R)  cout << "No" << endl;
  else cout <<"Yes" << endl;
}
  