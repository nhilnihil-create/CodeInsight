#include <iostream>
#include <string>
 
using namespace std;
 
int main(void)
{
  string s;
  cin >> s;
  if(s.length()==2) {
    cout << s << endl;
  } else {
    for(int i=2; i>=0; i--){
      cout << s[i];
    }
    cout << endl;
  }
}