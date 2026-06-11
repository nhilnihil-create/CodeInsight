#include<iostream>
using namespace std;
int main(void){
  int a,b,c = 0;
 cin >> a;
  string s = to_string(a);
  for(int i =0;i < s.size();i++){
    if(s.at(i) == '2'){
      c++;
    }
  }
  cout << c;
}