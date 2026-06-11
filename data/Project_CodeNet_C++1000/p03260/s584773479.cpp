#include <bits/stdc++.h>

using namespace std;

int maximo(int a, int b){
  if(a > b)
    return a;
  return b;
}

int main() {
  int a, b, flag =0;
  cin >> a >> b;
  for(int i = 1; i <= 3; i++){
    if((a * b * i)%2 != 0){
      flag = 1;
    }
  }

  if(flag)
    cout << "Yes" << endl;
  else
  {
    cout << "No" << endl;
  }
  

}