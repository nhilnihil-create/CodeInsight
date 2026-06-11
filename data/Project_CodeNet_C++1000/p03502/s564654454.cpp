#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int num = N;
  int H=0;
  while(num){
    H += num % 10;
    num /= 10;
  }
  if(N%H==0){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}
