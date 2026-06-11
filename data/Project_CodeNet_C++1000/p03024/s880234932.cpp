#include<iostream>
using namespace std;

int main(){
  string s;
  cin >> s;
  int num = s.size();
  int count = 0;
  //cout << num << endl;
  for(int i = 0; i < num; i++){
    if(s[i] == 'x'){
      count++;
    }
  }
  if(count >= 8){
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
  }
  return 0;
}