#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <functional>
#include <utility>
using namespace std;


int main(){
  long long n;
  cin >> n;
  for(long long i = n; i > 0; i--){
    long long k = pow(i, 0.5);
    if(k * k == i){
      cout << i << endl;
      break;
    }
  }

}