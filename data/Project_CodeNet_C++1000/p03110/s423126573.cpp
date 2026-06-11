#include <iostream>
#include <iomanip>

using namespace std;

int main() {

  int n;
  double bubble, pliefsto, gappy;
  string str;
  cin >> n;
  for(int i = 1;i <= n;i++){
    cin >> pliefsto >> str;
    if(str == "BTC"){
      bubble += pliefsto * 380000;
    }else{
      bubble += pliefsto;
    }
  }
  cout << fixed << setprecision(10) << bubble;
  return 0;
}
