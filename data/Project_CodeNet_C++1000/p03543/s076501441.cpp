#include <bits/stdc++.h>
using namespace std;

int main(){
  int N, a1, a2;
  cin >> N;
  a1 = N / 10;
  a2 = N - (N/1000 * 1000);
  if(a1 % 111 == 0 || a2 % 111 == 0){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
}
  