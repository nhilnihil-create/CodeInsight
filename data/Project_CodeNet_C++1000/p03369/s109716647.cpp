#include <iostream>
#include <string>

using namespace std;

int main(){
  int price[]={100,100,100};
  int res = 700;
  string s;
  cin >> s;

  for (int i=0;i<=s.size();i++){
    if (s[i] == 'o'){
      res += price[i];
    }
  }
  cout << res << endl;
  return 0;
}
