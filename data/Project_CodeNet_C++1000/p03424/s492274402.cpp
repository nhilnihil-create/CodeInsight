#include <iostream>
using namespace std;
int main(void){
    // Your code here!
  int i;
  cin >> i;
  int k=0;
  while(k<i){
    string j;
    cin >> j;
    if(j=="Y"){
      cout << "Four";
      k=i;
    }
    else if(k== i-1){
      cout << "Three";
      k++;
    }
    else{
      k++;
    }
  }
}