#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
int main(){
  int d;
  cin >> d;
  if (d == 25){
    cout << "Christmas\n";
  }
  if (d == 24){
    cout << "Christmas Eve\n";
  }
  if (d == 23){
    cout << "Christmas Eve Eve\n";
  }
  if (d == 22){
    cout << "Christmas Eve Eve Eve\n";
  }      
  return 0; 
}