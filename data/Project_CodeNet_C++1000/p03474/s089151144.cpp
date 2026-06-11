#include <iostream>
#include <vector>
using namespace std;


int main(void){
   int a,b;
   cin >> a >> b;
   string s;
   cin >> s;
   
  if(s[a] != '-'){
      cout << "No" << endl;
      return 0;
  }
   
  for(int i = 0;i < s.size();i++){
      if(i == a)continue;
       
      if(!('0' <= s[i] && s[i] <= '9')){
          cout << "No" << endl;
          return 0;
      }
  }
  cout << "Yes" << endl;

}
