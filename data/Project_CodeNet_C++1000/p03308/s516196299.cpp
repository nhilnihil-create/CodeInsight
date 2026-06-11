#include <bits/stdc++.h>
using namespace std;


int main(){
  int d;
  int a[100];
  cin >> d;
  for (int i = 0; i < d; i++){
    cin >> a[i];
  }

  int tmp_max = 0;
  int tmp_min = 1000000000;
  for (int i = 0; i < d; i++){
    tmp_max = max(tmp_max, a[i]);
    tmp_min = min(tmp_min, a[i]);
  }
  cout << tmp_max - tmp_min << endl;

}



  
    