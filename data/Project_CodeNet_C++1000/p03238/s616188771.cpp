#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

void solve(){
  int n; cin >> n;
  if(n == 1){
    cout << "Hello World\n";
  }
  else{
    int a, b; cin >> a >> b;
    cout << a + b << endl;
  }
  return;
}

int main(){
  solve();
  return 0;
}
