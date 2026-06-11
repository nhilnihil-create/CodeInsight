#include<iostream>
#include<string>
using namespace std;
 
int main(){
  int a = 0, b = 0, c = 0;
  string s;
  cin >> s;
  for(int i = 0;i < 3;i++){
    if(s.at(i) == 'a'){
      a++;
    }
    else if(s.at(i) == 'b'){
      b++;
    }
    else if(s.at(i) == 'c'){
      c++;
    }
  }
  if(a == 1&& b == 1 && c == 1){
    cout << "Yes";
  }
  else{
    cout << "No";
  }
}
 