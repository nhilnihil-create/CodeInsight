#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, n) for (int i = 1; i <= (int)(n); i++)

int main(){
  int N;
  cin >> N;

  int max = 1;

  int power;
  int power_of;
  for (int i = 1; i < 35; i++)
  {
    power_of = 2;
    if (i == 1){
      continue;
    }
    while(N >= pow(i, power_of)){
      if (max < pow(i, power_of)){
        max = pow(i, power_of);
      }
      power_of += 1;
    }
  }

  cout << max << endl;
  
}