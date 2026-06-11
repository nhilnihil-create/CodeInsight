#include<iostream>
using namespace std;
int main(){
  char s,t;cin >> s >>t;
  if(s > t)cout << ">" << endl;
  else if(s < t) cout << "<" << endl;
  else cout << "=" << endl;
}