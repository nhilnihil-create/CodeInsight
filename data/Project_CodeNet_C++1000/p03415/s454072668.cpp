#include<iostream>
using namespace std;
int main(){
  for(int i = 0; i < 9; ++i){
    char c; cin >> c;
    if(i%4)continue;
    cout << c;
  }
  cout << endl;
}