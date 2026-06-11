#include <bits/stdc++.h>
using namespace std;

int main(){
  int A , B , i = 0;
  cin >> A >> B;
  for (int k = 0; A <= B; k++){
    if (A % 10 == A / 10000 &&  A % 100 /10 == A % 10000 /1000){
      i += 1;
    }
    A++;
  }
  cout << i << endl;
}