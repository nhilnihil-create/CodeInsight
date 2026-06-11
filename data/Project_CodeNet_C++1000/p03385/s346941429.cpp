#include <iostream>
#include <string>
using namespace std;

int main()
{
  string s;
  cin >> s;
  bool abc[3] = {false, false, false};
  for(auto& i : s){
	abc[i - 'a'] = true;
  }
  if(abc[0]&&abc[1]&&abc[2]){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
  return 0;
}