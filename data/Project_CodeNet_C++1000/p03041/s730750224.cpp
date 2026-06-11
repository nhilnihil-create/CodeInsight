#include <iostream>
using namespace std;
int main(){
  int a,b;
  string s;
  cin >> a >> b;
  cin >> s;
  if (islower(s[b-1])){
    s[b-1]=toupper(s[b-1]);
    cout << s << endl;
  }
  else {
    s[b-1]=tolower(s[b-1]);
    cout << s << endl;
  }
}