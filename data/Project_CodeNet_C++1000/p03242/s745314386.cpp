#include <iostream>
#include <iomanip>

using namespace std;

int main() {

  int a, b, c;
  //cin >> a;
  double ans, ra, rb;
  string weatherReport;
  cin >> weatherReport;
  for(int i = 0;i < weatherReport.size();i++){
    if(weatherReport[i] == '9'){
      cout << 1;
    }else{
      cout << 9;
    }
  }
  return 0;
}
