#include <bits/stdc++.h>
using namespace std;

int main(){
  long long N;
  cin >> N;
  long long t = N, f = 0;
  while (t > 0){
    f += t % 10;
    t /= 10;
  }
  
  if (N % f == 0){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
}