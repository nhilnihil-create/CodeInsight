using namespace std;
#include<iostream>
int main(){
  int A, B;
  cin >> A >> B;
  if (A+B > 16){
    cout << ":(" << endl;
    return(0);
  }
  if ( A <= 16 && A >= 1 && B <= 16 && B >= 1){
    if ( A <= 8 && B <= 8){
      cout << "Yay!" << endl;
    }
    else{
      cout << ":(" << endl;
    }
  }
  return(0);
}