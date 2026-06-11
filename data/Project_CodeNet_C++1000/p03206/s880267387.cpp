#include<iostream>
using namespace std;

int main(){
  int D;
  cin >> D;
  string C = "Christmas";
  for(int i=25; D<i; i--){
    C += " Eve";
  }
  cout << C << endl;
  return 0;
}