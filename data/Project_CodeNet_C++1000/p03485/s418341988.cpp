#include <bits/stdc++.h>
using namespace std;

int main(){
  int a, b;
  cin >> a >> b;

  int mean = (a + b) / 2;
  
  int r_mean;

  if((a + b) % 2 != 0){
    r_mean = mean + 1;
  }else{
    r_mean = mean;
  }

  cout << r_mean << endl; 
}
