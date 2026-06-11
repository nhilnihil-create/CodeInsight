#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
  int n;
  cin >> n;
  int abNum = 0;
  int aNum = 0;
  int bNum = 0;
  int mNum = 0;
  for(int i=0; i<n; i++){
    string str;
    cin >> str;
    for(int j=0; j<str.length()-1; j++){
      if(str[j] == 'A' && str[j+1] == 'B') abNum++;
    }
    if(str[0] == 'B' && str[str.length()-1] == 'A') mNum++;
    else if(str[str.length()-1] == 'A') aNum++;
    else if(str[0] == 'B') bNum++;
  }
  if(n == 1) cout << abNum << endl;
  else{
    if(aNum != 0 || bNum != 0){
      cout << abNum + min(aNum, bNum) + mNum << endl;
    }else{
      if(mNum != 0) cout << abNum + mNum - 1 << endl;
      else cout << abNum << endl;
    }
  }
  return 0;
}
  