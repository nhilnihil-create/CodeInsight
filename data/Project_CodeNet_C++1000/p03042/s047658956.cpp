#include<iostream>
using namespace std;

int main(){
  int S;  cin >> S;
  int A = S/100;
  int B = S - A*100;
  if(1 <= A && A <= 12){
    if(1 <= B && B <= 12){
      cout << "AMBIGUOUS" << endl;
    }else if(0 <= B && B <= 99){
      cout << "MMYY" << endl;
    }
  }else{
    if(1 <= B && B <= 12){
      cout << "YYMM" << endl;
    }else{
      cout << "NA" << endl;
    }
  }
}
