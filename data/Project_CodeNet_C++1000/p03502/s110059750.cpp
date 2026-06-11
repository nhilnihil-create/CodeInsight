#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  int m = n;
  int c = 0;
  while(m > 0){
    c += m % 10;
    m /= 10;
  }
  if(n % c == 0){
    cout << "Yes";
  }else{
    cout << "No";
  }
}
