#include <bits/stdc++.h>
using namespace std;



int main() {
  int N,id,sum = 0;
  double ave,sa = 100;
 
  cin >> N;

  int a[100];

  for (int i = 0;i < N;i++){
    cin >> a[i];
  }

  for(int i = 0;i < N;i++){
    sum = sum + a[i];
  }

  ave = (double)sum / N ;

  for (int i = 0;i < N;i++){
    if ( sa > abs(ave - a[i])){
      sa = abs(ave - a[i]);
      id = i;
    }
  }
  cout << id << endl;
}
