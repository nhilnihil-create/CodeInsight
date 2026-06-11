#include <bits/stdc++.h>
using namespace std;

int main(){
  vector<char> MY(15);
  for(int i=0;i<15;i++){
    cin >> MY.at(i);
  }
  int count=0;
  for(int i=0;i<15;i++){
    if(MY.at(i)=='x'){
      count++;
    }
  }
  if(count<8){
    cout << "YES" << endl;
  }
  else cout << "NO" << endl;
}