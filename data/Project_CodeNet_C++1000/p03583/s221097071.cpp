#include <iostream>
using namespace std;

int main(){
  double n;
  cin >> n;
  for(double i=1.0; i<=3500; i+=1.0){
    for(double j=1.0; j<=3500; j+=1.0){
  	  double w = (n*i*j)/(4*i*j-n*i-n*j);
      if(w == (int)w && w > 0){
        cout << (int)i << " " << (int)j << " " << (int)w;
        return 0;
      }
    }
  }
}
