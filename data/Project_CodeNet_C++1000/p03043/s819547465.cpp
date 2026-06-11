#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main(){
  long double n,k;
  cin >> n >> k;
  int p,i;
  long double x=0;
  for(i=1;i<=n;i++){
    p=0;
    while(1){
      if(i*pow(2,p)<k) p++;
      else break;
    }
    x += 1/n*pow(0.5,p);
  }
  cout << fixed << setprecision(15) << x << "\n";
  return 0;
}