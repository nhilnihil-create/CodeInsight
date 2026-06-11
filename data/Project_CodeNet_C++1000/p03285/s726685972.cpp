#include <iostream>

using namespace std;

int const NMAX = 100;
int v[1 + NMAX];

int main() {

  int n;
  cin >> n;
  v[0] = 1;
  for(int i = 1;i <= n;i++){
    if(i - 4 >= 0){
      v[i] += v[i-4];
    }
    if(i - 7 >= 0){
      v[i] += v[i-7];
    }
  }
  if(v[n] >= 1){
    cout << "Yes";
  }else{
    cout << "No";
  }
  return 0;
}
