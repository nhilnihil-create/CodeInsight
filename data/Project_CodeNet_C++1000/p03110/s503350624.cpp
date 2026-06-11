#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <string>
#include <map>
#include <list>
using namespace std;

int main() {
  int n;
  cin >> n;
  long double x[n];
  string u[n];

  long double res=0;
  for(int i = 0; i < n; ++i){
    cin >> x[i] >> u[i];
    if(u[i]=="BTC"){
      x[i] *= 380000.0;
    }
    res+=x[i];
  }
  
  cout << res << endl;
}

