#include <iostream>
using namespace std;

int main(){
  int num, coin;
  cin >> num; //支払額
  cin >> coin; //1円の枚数
  
  if(coin >= num % 500){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
}