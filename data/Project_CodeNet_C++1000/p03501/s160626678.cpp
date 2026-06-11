#include <bits/stdc++.h>
using namespace std;
int main(){
  int N, A, B;
  cin >> N >> A >> B ;
  int p1, p2;
  p1 = N * A, p2 = B;
  
  if (p1 < p2){
    cout << p1 << endl;
  }
  else {
    cout << p2 << endl;
  }


}