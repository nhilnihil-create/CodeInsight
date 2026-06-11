#include<iostream>
using namespace std;

int main(){
  string n;
  cin >> n;
  for(int i=0; i<3; i++){
    n[i] = (n[i] == '9' ? '1' : '9');
  }
  cout << n << endl;
  return 0;
}