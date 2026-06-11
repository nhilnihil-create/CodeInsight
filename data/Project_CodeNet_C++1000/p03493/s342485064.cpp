#include<bits/stdc++.h>
using namespace std;
int main(){
  string str;
  int count = 0;
  cin >> str;
  for(int i =0;i < 3;i++){
    if(str.at(i) == '1'){
      count += 1;
    }
  }
  cout << count << endl;
  return 0;
}